#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define loop3(i,j,k,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)
#define loop4(i,j,k,l,a) for(int i=0; i<a; i++)for(int j=0; j<a; j++)if(i!=j)for(int k=0; k<a; k++)if(i!=k&&j!=k)for(int l=0; l<a; l++)if(i!=l&&j!=l&&k!=l)
#define rep1(i,a) for(int i=1; i<=a; i++)

#define scnd1(a) scanf("%d", &a)
#define scnd2(a,b) scanf("%d%d", &a,&b)
#define scnd3(a,b,c) scanf("%d%d%d", &a,&b,&c)
#define scnd4(a,b,c,d) scanf("%d%d%d%d", &a,&b,&c,&d)

#define cin1(a) cin >> a;
#define cin2(a,b) cin >> a >> b;
#define cin3(a,b,c) cin >> a >> b >> c;
#define cin4(a,b,c,d) cin >> a >> b >> c >> d;
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define prtd1(a) printf("%d\n", a)
#define prtd2(a,b) printf("%d %d\n", a,b)
#define prtd3(a,b,c) printf("%d %d %d\n", a,b,c)
#define prtd4(a,b,c,d) printf("%d %d %d %d\n", a,b,c,d)

#define mem(a,n) memset( a, n, sizeof(a))
typedef long long ll;
const int INF = 1e9;
const ll LLINF = 1e18;


int main() {
    int N;
    string S;
    cin>>N>>S;
    
    bool f = false;
    int animals[100009];
    for(int i=0;i<8;i++){
        mem(animals,0);
        if(i&(1<<0)) animals[0]=1;
        if(i&(1<<1)) animals[1]=1;
        if(i&(1<<2)) animals[2]=1;
        
        for(int j=2; j<N-1; j++){
            if((animals[j]==0 && S[j]=='o') || (animals[j]==1 && S[j]=='x')){
                animals[j+1] = animals[j-1];
            }else{
                animals[j+1] = 1 - animals[j-1];
            }
        }
        
        if((animals[0]==0 && S[0]=='o') || (animals[0]==1 && S[0]=='x')){
            if(animals[N-1]!=animals[1]) continue;
        }else{
            if(animals[N-1]==animals[1]) continue;
        }
        
        if((animals[1]==0 && S[1]=='o') || (animals[1]==1 && S[1]=='x')){
            if(animals[0]!=animals[2]) continue;
        }else{
            if(animals[0]==animals[2]) continue;
        }
        
        if((animals[N-1]==0 && S[N-1]=='o') || (animals[N-1]==1 && S[N-1]=='x')){
            if(animals[N-2]!=animals[0]) continue;
        }else{
            if(animals[N-2]==animals[0]) continue;
        }
        f = true;
        break;
    }
    
    if(f){
        rep(i,N){
            if(animals[i]==0) cout<<'S';
            else cout<<'W';
        }
        cout<<endl;
    }else{
        cout1(-1);
    }
}