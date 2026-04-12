//        VIVEK UPADHYAY
//        MANIT, BHOPAL(M.P)


//                         JAB-TAK TODEGA NHI,
//                         TAB -TAK CHODEGA NHI :D
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<cstdlib>
#include<unistd.h>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<utility>
#include<cmath>
#include<set>
#include<unordered_map>
#include<cstdio>
#include<map>
#include<numeric>
using namespace std;
#define F first
#define S second
#define mk(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define LINE cout<<endl
#define ok cout<<"ok\n" ;
typedef long long ll;
const int MAXN = 1e6 + 10 ;
const int MAX = 1e7 ;
double pi = 3.1415926535897932384626433832795;
const ll inf=1e18 ;
int main() {
    int N , M ;
    cin >> N >> M ;
    string s[N] ;
    for(int i=0;i<N;i++)
            cin >> s[i] ;
    
    for(int i=0;i<N;i++){
        int cnt=0 ;
        for(int j=0;j<M;j++)
            if(s[i][j]=='.') cnt++ ;
        if(cnt==M)
            for(int j=0;j<M;j++)
                s[i][j]='$' ;
    }
    for(int i=0;i<M;i++)
    {
        int cnt= 0 ;
        for(int j=0;j<N;j++)
            if(s[j][i]=='.'|| s[j][i]=='$') cnt++ ;
        if(cnt==N)
            for(int j=0;j<N;j++)
                s[j][i]='$' ;
    }
    for(int i=0;i<N;i++){
        bool flag = true ;
        for(int j=0;j<M;j++)
            if(s[i][j]!='$'){
                cout<<s[i][j];
                flag=false ;
            }
        if(flag==false)
        cout<<endl;
    }
    return 0 ;
}
