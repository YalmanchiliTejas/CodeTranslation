#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )

 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);

int main(){
    int N;
    cin >> N;
    vector<int> A;
    rep(i,N) {
        int a;
        cin >> a;
        if (A.size()==0) {
            A.push_back(a);
        }
        else {
            auto idx = lower_bound(A.rbegin(),A.rend(), a) - A.rbegin();
            //cout << "input:" << a << " idx:" << idx << endl;
            if (idx==0) {
                A.push_back(a);
            }
            else {
                //cout << "input:" << a << " idx:" << A.size()-idx << endl;
                A[A.size()-idx] = a;
            }
        }
        //sort(A.begin(),A.end());
    }
    int ans = A.size();
    cout << ans << endl;

    //rep(i,A.size()) {
    //    cout << A[i] << " ";
    //}
    //cout << endl;
}
