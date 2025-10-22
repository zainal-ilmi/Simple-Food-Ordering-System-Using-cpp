#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct MenuItem {
    int id;
    string name;
    double price;
    MenuItem* next;
};

MenuItem* head = nullptr;
MenuItem* orderHead = nullptr;
int menuID = 1;


void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void displayMenu(MenuItem* head) {
    clearScreen(); // Tambahkan clear screen
    cout << "==========================================\n";
    cout << "     ---------- DAFTAR MENU ---------- \n";
    cout << "==========================================\n";

    if (!head) {
        cout << "Menu kosong.\n";
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << left << setw(5) << "ID" << setw(20) << "Nama" << setw(10) << "Harga" << endl;
    cout << "--------------------------------\n";
    MenuItem* current = head;
    while (current) {
        cout << left << setw(5) << current->id << setw(20) << current->name << "Rp " << current->price << endl;
        current = current->next;
    }
    cout << "\nTekan Enter untuk kembali...";
    cin.ignore(); // Tambahkan input enter
    cin.get();
}

void addMenuItem() {
    clearScreen();
    MenuItem* newItem = new MenuItem;
    newItem->id = menuID++;
    cout << "==========================================\n";
    cout << "       -------- TAMBAH MENU --------  \n";
    cout << "==========================================\n";
    cout << "Masukkan Nama Makanan: ";
    cin.ignore();
    getline(cin, newItem->name);
    cout << "_________________________________________\n";
    cout << "Masukkan Harga Makanan: ";
    cin >> newItem->price;
    newItem->next = nullptr;

    if (!head) {
        head = newItem;
    } else {
        MenuItem* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
    cout << "_________________________________________\n";
    cout << "  **** Menu berhasil ditambahkan ****!\n";
    cout << "\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void deleteMenuItem() {
    clearScreen();
    cout << "==========================================\n";
    cout << "       -------- HAPUS MENU --------  \n";
    cout << "==========================================\n";
    displayMenu(head);

    int id;
    cout << "Masukkan ID menu yang ingin dihapus: ";
    cin >> id;

    MenuItem* current = head;
    MenuItem* prev = nullptr;

    while (current && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        cout << "Menu tidak ditemukan!\n";
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    if (!prev) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    delete current;
    cout << "Menu berhasil dihapus!\n";
    cout << "\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void editMenuItem() {
    clearScreen();
    cout << "==========================================\n";
    cout << "       -------- UBAH MENU --------  \n";
    cout << "==========================================\n";
    displayMenu(head);

    int id;
    cout << "Masukkan ID menu yang ingin diubah: ";
    cin >> id;

    MenuItem* current = head;
    while (current && current->id != id) {
        current = current->next;
    }

    if (!current) {
        cout << "Menu tidak ditemukan!\n";
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    cout << "_________________________________________\n";
    cout << "Masukkan Nama Makanan Baru: ";
    cin.ignore();
    getline(cin, current->name);
    cout << "_________________________________________\n";
    cout << "Masukkan Harga Makanan Baru: ";
    cin >> current->price;
    cout << "_________________________________________\n";
    cout << "   ****Menu berhasil diubah ****!\n";
    cout << "\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void orderMenuItem() {
    clearScreen();
    cout << "==========================================\n";
    cout << "       -------- PESAN MENU --------  \n";
    cout << "==========================================\n";

    if (!head) {
        cout << "Belum ada daftar menu tersedia.\n";
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    displayMenu(head);

    int id;
    cout << "Masukkan ID menu yang ingin dipesan: ";
    cin >> id;

    MenuItem* current = head;
    while (current && current->id != id) {
        current = current->next;
    }

    if (!current) {
        cout << "Menu tidak ditemukan!\n";
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    MenuItem* orderItem = new MenuItem(*current);
    orderItem->next = nullptr;

    if (!orderHead) {
        orderHead = orderItem;
    } else {
        MenuItem* temp = orderHead;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = orderItem;
    }
    cout << "_________________________________________\n";
    cout << "    **** Menu berhasil dipesan ****!\n";
    cout << "\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}


void displayOrders() {
    clearScreen();
    cout << "==========================================\n";
    cout << "  --------- RIWAYAT PESANAN -------- \n";
    cout << "==========================================\n";

    if (!orderHead) {
        cout << "Belum ada pesanan.\n";
    } else {
        cout << left << setw(5) << "ID" << setw(20) << "Nama" << setw(10) << "Harga" << endl;
        cout << "--------------------------------\n";

        double totalPrice = 0;
        MenuItem* current = orderHead;
        while (current) {
            cout << left << setw(5) << current->id << setw(20) << current->name << "Rp " << current->price << endl;
            totalPrice += current->price;
            current = current->next;
        }
        cout << "--------------------------------\n";
        cout << "Total Harga: Rp " << totalPrice << endl;
    }

    cout << "\nTekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void mainMenu() {
    int choice;
    do {
        clearScreen();
        cout << "==========================================\n";
        cout << "   ---------- Selamat Datang ----------   \n";
        cout << "-------- Sistem Pemesanan Makanan --------\n";
        cout << "==========================================\n";
        cout << "\n==========================================\n";
        cout << "Dibuat oleh: \n";
        cout << "Dhio Rizqi N.S  (23081010277)\n";
        cout << "M. Zainal Ilmi  (23081010072)\n";
        cout << "Nasywah Aulia   (23081010205)\n";
        cout << "Ailsa Farah     (23081010212)\n";
        cout << "==========================================\n";
        cout << "\n==========================================\n";
        cout << "   ---------- Selamat Datang ----------   \n";
        cout << "-------- Sistem Pemesanan Makanan --------\n";
        cout << "==========================================\n";
        cout << "\n1. Master Menu\n";
        cout << "2. Pesan/Order\n";
        cout << "3. Riwayat Pesanan\n";
        cout << "4. Keluar\n";
        cout << "_________________________________________\n";
        cout << "Silahkan Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int masterChoice;
                do {
                    clearScreen();
                    cout << "==========================================\n";
                    cout << "     ---------- Master Menu ---------- \n";
                    cout << "==========================================\n";
                    cout << "1. Lihat\n";
                    cout << "2. Tambah\n";
                    cout << "3. Hapus\n";
                    cout << "4. Ubah\n";
                    cout << "5. Kembali\n";
                    cout << "_________________________________________\n";
                    cout << "Silahkan Pilih opsi: ";
                    cin >> masterChoice;

                    switch (masterChoice) {
                        case 1: displayMenu(head); break;
                        case 2: addMenuItem(); break;
                        case 3: deleteMenuItem(); break;
                        case 4: editMenuItem(); break;
                    }
                } while (masterChoice != 5);
                break;
            }
            case 2: orderMenuItem(); break;
            case 3: displayOrders(); break;
            case 4:
                cout << "\nTerima kasih telah menggunakan aplikasi ini.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (choice != 4);
}

int main() {
    mainMenu();
    return 0;
}
