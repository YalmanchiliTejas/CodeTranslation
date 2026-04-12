#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
int a[205];

bool is_sorted() {
    for(int i = 1; i < N; i++) {
        if(a[i - 1] >= a[i]) return false;
    }
    return true;
}
vector<int> ans;

int main() {
    //cout.precision(10);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    while(!is_sorted()) {
        for(int i = 0; i < N; i++) {
            //cout << a[i] << " ";
        }
        //cout << endl;
        //cout << 1 << endl;
        ans.push_back(1);
        int tmp = a[0];
        for(int i = 0; i < N - 1; i++) {
            a[i] = a[i + 1];
        }
        a[N - 1] = tmp;
        if(is_sorted()) break;
        if(a[0] < a[N - 1]) {
            if(a[0] == 0 && a[N - 1] == (N - 1)) continue;
            //cout << N - 1 << endl;
            ans.push_back(N - 1);
            swap(a[0], a[N - 1]);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}