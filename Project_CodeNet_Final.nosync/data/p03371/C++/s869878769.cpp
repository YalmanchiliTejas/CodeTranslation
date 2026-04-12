#include<bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<=(n);i++)
#define rep3(i,i0,n) for(int i=i0;i<(n);i++)
#define pb push_back
#define mod 1000000007
#define INF 2000000000
typedef long long ll;
bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
        
    }else{
        return a.second < b.second;
    }
}
// 入力
 
 
 
int main() {
    
    ll A,B,C,X,Y,ans;
    cin >>A>>B>>C>>X>>Y;
    if(A+B < 2*C){
        ans = A*X+B*Y;
    }else if(A < 2*C && B < 2*C){
        if(X > Y){
            ans = Y*2*C + (X-Y)*A;
        }else{
            ans = X*2*C + (Y-X)*B;
        }
         
    }else if(B < 2*C){
        if(X > Y){
            ans = X*2*C;
        }else{
            ans = X*2*C + (Y-X)*B;
        } 
    }else if(A < 2*C){
        if(X > Y){
            ans = Y*2*C + (X-Y)*A;
        }else{
            ans = Y*2*C;
        } 
    }else{
        if(X > Y){
            ans = X*2*C;
        }else{
            ans = Y*2*C;
        } 
    }
    cout << ans << endl;
    
    
    
    return 0;
    
 
}