#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;

int modd=1e9+7;

vector<int> arr;
vector<vector<long long> > ans;

void update(int l, int r, long long sum){
    if(l>r) return;
    if(ans[l][r]!=-1) return;
    if(l==r) ans[l][r]=arr[l];
    else{
        update(l+1,r,sum-arr[l]); update(l,r-1,sum-arr[r]);
       ans[l][r]=sum-min(ans[l+1][r],ans[l][r-1]);
    }
}

int main(){
    int n; cin>>n;

    arr.resize(n); long long sum=0;
    for(int i=0; i<n; i++){ cin>>arr[i]; sum+=arr[i]; }

    ans.resize(n);
    vector<long long> temp(n); for(int i=0; i<n; i++) temp[i]=-1;
    for(int i=0; i<n; i++){
        ans[i]=temp;
    }

    update(0,n-1,sum);
    cout<<2*ans[0][n-1]-sum<<endl;

}
