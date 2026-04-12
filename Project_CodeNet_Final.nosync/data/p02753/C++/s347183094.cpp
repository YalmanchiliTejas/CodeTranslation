#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <cstdlib>
#define mem(i,a) memset(i,a,sizeof(i))
#define PI acos(-1.0)
#define DMAX 80000+5
#define eps 1e-8
#define mp make_pair
#define INF 1000000000+9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
inline void read(int &f){
    f=0;
    ll x=1;
    char ch=getchar();
    while(ch<48 || ch>57) {
        if(ch=='-') {
            x=-1;
        }
        ch=getchar();
    }
    while(ch<=57 && ch>=48) {
        f=f*10+ch-'0';
        ch=getchar();
    }
    f*=x;
}
string s;
int cnta,cntb;
int main(){
    cin>>s;
    for(int i=0;i<3;i++){
        if(s[i]=='A'){
            cnta++;
        }
        else{
            cntb++;
        }
    }
    if(!cnta || !cntb){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}