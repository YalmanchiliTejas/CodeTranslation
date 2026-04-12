#include <iostream>
using namespace std;
int main()
{int r,g,h;
 cin>>r>>g>>h;
 int ans=r*100+g*10+h;
 if(ans%4==0){cout << "YES" << endl;}
 else{cout << "NO" << endl;}
}