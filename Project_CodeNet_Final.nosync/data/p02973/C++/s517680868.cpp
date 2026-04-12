#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++) cin >> A[i];
    
    deque<int> l;
    for(int i=0; i<N; i++){
        if(l.empty()){
            l.push_front(A[i]);
            continue;
        }

        auto it = lower_bound(l.begin(), l.end(), A[i]);
        if(it == l.begin())l.push_front(A[i]);
        else{
            *(--it) = A[i];
        }
    }
    cout << l.size() << endl;

    return 0;
}
