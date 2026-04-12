#include<iostream>
using namespace std;

int r, g, b;

int main(){
cin >> r >> g >> b;
cout <<( (r*100+g*10+b) % 4 == 0 ?"YES":"NO");

return 0;
}
