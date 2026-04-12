#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define INF 1000000000000 //10^12

int main(){
    string s;
    cin >>s;
    if(s.c_str()[0] ==s.c_str()[1] &&s.c_str()[1]==s.c_str()[2]) cout<<"No"<<endl;
    else cout << "Yes" <<endl;
}