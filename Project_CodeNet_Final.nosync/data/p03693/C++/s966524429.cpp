#include<iostream>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int check4 = (g*10+b) % 4;
    if(check4 == 0)
        {
             cout << "YES" << endl; 
        }
    else
        { 
            cout << "NO" << endl;
          }

}