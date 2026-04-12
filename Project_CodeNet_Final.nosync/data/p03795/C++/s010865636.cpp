#include <iostream>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n;  cin >> n;
    int count = 0;
    for(int i = n; i >= 15; i-=15)   count++;
    cout << 800*n-count*200 << endl;
}
