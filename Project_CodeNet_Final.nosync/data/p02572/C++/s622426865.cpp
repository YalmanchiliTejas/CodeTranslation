#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    ll sum = A[0];
    ll ans = 0;
    for(int i=1;i<N;i++){
        ans += sum * A[i];
        ans %= 1000000007;
        sum += A[i];
        sum %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}