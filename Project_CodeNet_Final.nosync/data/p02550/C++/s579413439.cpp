#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
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
#define NIL -1
//#define INFTY 1000000000000000000

int main(){
    LL n;
    LL x;
    LL m;
    cin >> n >> x >> m;
    vector<bool> is_visit(m, false);
    vector<LL> visit_idx(m, NIL);
    is_visit[x]=true;
    visit_idx[x]=1;
    LL first_visit_idx=NIL;
    LL second_visit_val=NIL;
    LL second_visit_idx=NIL;
    LL ans=0;
    LL tmp_x;
    if(n<=m){
        tmp_x=x;
        for(LL i=1; i<=n; i++){
            ans+=tmp_x;
            tmp_x=(tmp_x*tmp_x)%m;
        }
    }else{
        LL tmp_x=x;
        if(m==1){
            second_visit_val=n%m;
            ans=0;
        }else{
            for(LL i=2; i<=m; i++){
                tmp_x=(tmp_x*tmp_x)%m;
                if(is_visit[tmp_x]==true){
                    second_visit_val=tmp_x;
                    second_visit_idx=i;
                    break;
                }else{
                    is_visit[tmp_x]=true;
                    visit_idx[tmp_x]=i;
                }
            }
            first_visit_idx=visit_idx[second_visit_val];
            tmp_x=x;
            for(LL i=1; i<first_visit_idx; i++){
                ans+=tmp_x;
                tmp_x=(tmp_x*tmp_x)%m;
            }
            tmp_x=second_visit_val;
            LL tmp_ans=0;
            for(LL i=first_visit_idx; i<second_visit_idx; i++){
                tmp_ans+=tmp_x;
                tmp_x=(tmp_x*tmp_x)%m;
            }
            LL res=n-(first_visit_idx-1);
            ans=ans+tmp_ans*(res/(second_visit_idx-first_visit_idx));
            res=res%(second_visit_idx-first_visit_idx);
            tmp_x=second_visit_val;
            for(LL i=0; i<res; i++){
                ans+=tmp_x;
                tmp_x=(tmp_x*tmp_x)%m;            
            }
        }
    }

    cout << ans << endl;

    return 0;
}
