#include <bits/stdc++.h>

#define REP(i,n) for(int i = 0;i < n;i++)
#define REPR(i,n) for(int i = n-1;i >= 0;i--)
#define FOR(i,m,n) for(int i = m;i < n;i++)
#define PRINT(s) cout<<s
#define PRINTS(s) cout<<s<<' '
#define PRINTL(s) cout<<s<<endl
#define INF 2e9
#define ALL(v) v.begin(),v.end()
#define ll long long

using namespace std;

string pop_back(string s){
    string t = s.substr(0,s.size()-1);
    return t;
}

int gcd(int max,int min){
    
    if(max<min){
        int tmp=max;
        max=min;
        min=tmp;
    }

    if(max%min==0)return min;
    else return gcd(min,max%min);

}

int main(void){

    int x,y,z;
    cin>>x>>y>>z;

    int people=0;
    int haba=0;
    while(haba<=x){
        people++;
        haba=people*y+(people+1)*z;
    }
    cout<<people-1<<endl;

    return 0;
}


