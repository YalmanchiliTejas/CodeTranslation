#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int r,g,b;
    cin >> r >> g >> b;

    int num = 100 * r + 10 * g + 1 * b;
    if (num % 4 == 0){
        cout << "YES" << endl;
    } else{
        cout << "NO"<< endl;
    }
    return 0;
}