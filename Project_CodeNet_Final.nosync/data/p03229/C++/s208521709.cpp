#include <iostream>
//#include <set>
//#include <map>
//#include <iomanip>
#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
#include <vector>
//#include <string>
//#include <list>
//#include <deque>
//#include <unordered_map>
typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 200100
//#define NIL -1

int main() {
    int n;
    vector<LL> a;
    LL tmp_a;
    LL ans=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp_a;
        a.push_back(tmp_a);
    }
    sort(a.begin(), a.end());

    int min_idx=0;
    int max_idx=a.size()-1;
    LL left=a[min_idx];
    LL right=a[max_idx];
    ans+=right-left;
    min_idx++;
    max_idx--;

    //cout << left << " " << right << endl;
    vector<LL> cand(4);
    while(min_idx<=max_idx){
        cand[0]=abs(left-a[min_idx]);
        cand[1]=abs(left-a[max_idx]);
        cand[2]=abs(right-a[min_idx]);
        cand[3]=abs(right-a[max_idx]);
        int max_value =*max_element(cand.begin(),cand.end());
        for(int i=0; i<4; i++){
            if(max_value==cand[i]){
                ans+=cand[i];
                if(i==0){
                    left=a[min_idx];
                    min_idx++;
                }else if(i==1){
                    left=a[max_idx];
                    max_idx--;
                }else if(i==2){
                    right=a[min_idx];
                    min_idx++;
                }else{
                    right=a[max_idx];
                    max_idx--;
                }
                //cout << left << " " << right << endl;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}