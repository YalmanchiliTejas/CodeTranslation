#include <bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(),(obj).end()
#define sortall(obj) sort(ALL(obj));
typedef string str;

#define sts(a) string (a);cin >> a
#define For(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) For(i,0,n)
#define print(a) cout << a << endl

int main(){
    int a;cin >> a;
    if(a==7||a==5||a==3){
        print("YES");
    }else{
        print("NO");
    }
    return 0;
}