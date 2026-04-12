#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    deque<int> q;
    int ans = 1;
    q.push_front(A[0]);
    for(int i=1; i<N; i++){
        auto it = lower_bound(q.begin(), q.end(), A[i]);
        if(it == q.begin()){
            ans++;
            q.push_front(A[i]);
        }else{
            it--;
            *it = A[i];
        }
    }

    cout << ans << endl;

    return 0;
}
