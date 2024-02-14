#include <iostream>
using namespace std;

class VendingMachine {
private:
    int cashAvailable;

public:
    VendingMachine() {
        cashAvailable = 500;
    }

    VendingMachine(int initialCash) {
        cashAvailable = initialCash;
    }

    int getBalance() const {
        return cashAvailable;
    }

    void acceptAmount(int amountIn) {
        cashAvailable += amountIn;
    }
};

class ProductDispenser {
private:
    int availableItems;
    int price;

public:
    ProductDispenser() {
        availableItems = 50;
        price = 50;
    }

    ProductDispenser(int items, int priceIn) {
        availableItems = items;
        price = priceIn;
    }

    int getAvailableItems() const {
        return availableItems;
    }

    int getPrice() const {
        return price;
    }

    void sellProduct() {
        availableItems--;
    }
};

void displayMenu() {
    cout << "Добро пожаловать!\n";
    cout << "1. Конфеты\n";
    cout << "2. Чипсы\n";
    cout << "3. Жвачка\n";
    cout << "4. Печенье\n";
    cout << "Выберите продукт, введите номер: ";
}

void processSale(ProductDispenser& productDispenser, VendingMachine& cashRegister) {
    int productPrice = productDispenser.getPrice();
    int currentBalance = cashRegister.getBalance();
    int userMoneyInput;

    if (productDispenser.getAvailableItems() > 0) {
        cout << "Цена продукта: " << productPrice << "₽. Пожалуйста, внесите деньги: ";
        cin >> userMoneyInput;

        if (userMoneyInput >= productPrice) {
            if (currentBalance >= userMoneyInput - productPrice) {
                productDispenser.sellProduct();
                cashRegister.acceptAmount(productPrice);
                cout << "Ваш продукт выдан!\n";
                cout << "Сдача: " << userMoneyInput - productPrice << "₽.\n";
            }
            else {
                cout << "Нет возможности выдать сдачу :(\nПожалуйста, внесите другую сумму.\n";
            }
        }
        else {
            cout << "Недостаточно средств. Пожалуйста, внесите большую сумму.\n";
        }
    }
    else {
        cout << "Товар закончился :(\n";
    }
}

int main() {
    VendingMachine cashRegister(1000);
    ProductDispenser candies(200, 29), chips(50, 120), gum(100, 35), cookies(25, 50);

    int choice;
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1:
        processSale(candies, cashRegister);
        break;
    case 2:
        processSale(chips, cashRegister);
        break;
    case 3:
        processSale(gum, cashRegister);
        break;
    case 4:
        processSale(cookies, cashRegister);
        break;
    default:
        cout << "Неверный выбор.\n";
        break;
    }

    return 0;
}