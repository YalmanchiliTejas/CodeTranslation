#include <iostream>

int main(){

int x;

std::cin >> x;

int total = x * 800;

int diskon = (x / 15)*200;

int kembalian = total - diskon;

std::cout << kembalian;
}
