#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<utility>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    int n, ans = 1;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m = a[0];
    for(int i = 1; i < n; i++){
        if(m <= a[i]){
            ans++;
        }
        m = max(m, a[i]);
    }
    cout << ans << endl;
    return 0;
}
