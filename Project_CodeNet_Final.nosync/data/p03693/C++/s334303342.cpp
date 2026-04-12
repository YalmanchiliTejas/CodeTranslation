#include<iostream>
#include<string>
using namespace std;

int main()
{
    string r,g,b;
    cin >> r >> g >> b;
    int ans = stoi(r+g+b);
    if(ans%4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
