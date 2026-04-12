#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    ios::sync_with_stdio(false);
    vector<ii> nums;
    int n;
    cin>>n;
    int a,b;
    int rm=1000000001,rma=-1,bm=1000000001,bma=-1;
    for(int ctr1 = 0; ctr1 < n; ctr1++) {
        cin>>a>>b;
        nums.push_back(make_pair(a,ctr1));
        nums.push_back(make_pair(b,ctr1));
        if(a>b)
            swap(a,b);
        rm=min(rm,a);
        rma=max(rma,a);
        bm=min(bm,b);
        bma=max(bma,b);
    }
    sort(nums.begin(),nums.end());
    int ar[202020];
    int idx[202020];
    memset(ar,-1,sizeof(ar));
    int total_in = 0;
    ll rez = ((ll)(rma-rm))*(bma-bm);
    int f_s = n;
    multiset<int> uniq;
    for(int ctr1 = 0; ctr1 < nums.size(); ctr1++) {
        if(total_in == n) {
            rez = min(((ll)(*uniq.rbegin() - *uniq.begin()))*(nums[nums.size()-1].first-nums[f_s].first),rez);
        }
        if(ar[nums[ctr1].second] != -1) {
            f_s = min(f_s, idx[nums[ctr1].second]);
            uniq.erase(uniq.find(ar[nums[ctr1].second]));
            total_in--;
        }
        uniq.insert(nums[ctr1].first);
        ar[nums[ctr1].second] = nums[ctr1].first;
        idx[nums[ctr1].second] = ctr1;
        total_in++;
    }
    cout<<rez;
    return 0;
}
