#include <bits/stdc++.h>
using namespace std;
 
// a,b,cの最大値、最小値をそれぞれminimumの参照先、maximumの参照先に代入する

int main() {
    string n ;
    cin >>n;
    bool a=false,b=false;
    for(int i=0;i<3;i++){
        if(n.at(i)=='A'){
            a=true;
        }
        if(n.at(i)=='B'){
            b=true;
        }
    }
    if(a&&b)
    {cout << "Yes"<<endl;}
    else {
        cout << "No"<<endl;
    }
}
