#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define print(n) std::cout << n << std::endl
#define print_no_indention(n) std::cout << n
using namespace std;


int main() {
   int n;
   cin >> n;

   int count = n / 15;
   
   int sum = n * 800 - count * 200;
   print(sum);
}