#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    string s;
    bool is_ok=false;
    cin >> n;
    cin >> s;
    vector<LL> ans(n);
    for(LL i=0; i<2; i++){
        for(LL j=0; j<2; j++){
            if(is_ok==true){
                continue;
            }
            ans[0]=i;
            ans[1]=j;
            for(LL k=2; k<n; k++){
                if(s[k-1]=='o'){
                    if(ans[k-1]==0){
                        ans[k]=ans[k-2];
                    }else{
                        ans[k]=1-ans[k-2];
                    }
                }else{
                    if(ans[k-1]==0){
                        ans[k]=1-ans[k-2];
                    }else{
                        ans[k]=ans[k-2];
                    }
                }
            }
            if(s[n-1]=='o'){
                if(ans[n-1]==0){
                    if(ans[0]!=ans[n-2]){
                        continue;
                    }
                }else{
                    if(ans[0]==ans[n-2]){
                        continue;
                    }                    
                }
            }else{
                if(ans[n-1]==0){
                    if(ans[0]==ans[n-2]){
                        continue;
                    }
                }else{
                    if(ans[0]!=ans[n-2]){
                        continue;
                    }                    
                }
            }
            if(s[0]=='o'){
                if(ans[0]==0){
                    if(ans[1]!=ans[n-1]){
                        continue;
                    }
                }else{
                    if(ans[1]==ans[n-1]){
                        continue;
                    }                    
                }
            }else{
                if(ans[0]==0){
                    if(ans[1]==ans[n-1]){
                        continue;
                    }
                }else{
                    if(ans[1]!=ans[n-1]){
                        continue;
                    }
                }
            }
            is_ok=true;
        }
    }

    if(is_ok==false){
        cout << -1 << endl;
    }else{
        for(LL i=0; i<n; i++){
            if(ans[i]==0){
                cout << 'S';
            }else{
                cout << 'W';
            }
        }
        cout << endl;
    }

    return 0;
}
