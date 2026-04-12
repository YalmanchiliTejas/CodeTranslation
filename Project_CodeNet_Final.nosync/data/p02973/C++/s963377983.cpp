#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);
const int N=100001;
const int MOD=1e9+7;

int a[N];

int MinimumNumIncreasingSubsequences(int n)
{
    multiset<int> last;

    for (int i = 0; i < n; i++) {

        multiset<int>::iterator it = last.lower_bound(a[i]);

        if (it == last.begin())
            last.insert(a[i]);

        else {
            it--;
            last.erase(it);
            last.insert(a[i]);
        }
    }
    return last.size();
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    cout<<MinimumNumIncreasingSubsequences(n);


}



