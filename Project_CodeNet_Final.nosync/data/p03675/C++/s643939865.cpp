#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define debug(x) cerr << #x << " = " << (x) << endl;
template<typename T>
ostream& operator<<(ostream& o, vector<T>& v) {
    for (auto& x : v) o << x << ' ';
    return o;
}

int main(){
    std::ios_base::sync_with_stdio(false); cin.tie(0);

    int n; cin >> n;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    deque<int> dq;
    for (int i = 0; i < n; i++){
        if (i & 1){
            dq.push_front(arr[i]);
        } else {
            dq.push_back(arr[i]);
        }
    }
    if (n & 1){
        reverse(dq.begin(), dq.end());
    }
    for (int i = 0; i < n; i++){
        cout << dq[i] << " ";
    }
    cout << endl;

}
