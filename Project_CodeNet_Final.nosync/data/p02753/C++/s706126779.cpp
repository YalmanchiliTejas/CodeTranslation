#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int a = 0, b = 0;
    char x,y,z;
    cin >>s;
    x=s.at(0);
    y=s.at(1);
    z=s.at(2);
    if(x == 'A')a+=1;
       else if(x == 'B')b+=1;
    if(y == 'A')a+=1;
       else if(y == 'B')b+=1;
    if(z == 'A')a+=1;
       else if(z == 'B')b+=1;
    
    if(a==3 || b==3) cout <<"No"<<endl;
    else cout<<"Yes"<<endl;
}