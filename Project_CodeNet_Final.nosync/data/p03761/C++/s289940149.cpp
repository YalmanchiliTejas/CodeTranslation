#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;cin>>n;
    string arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
        sort(arr[i].begin(),arr[i].end());
    }if (n==1){
        cout<<arr[0]<<endl;
        return 0;
    }
    string ans="";
    int p=0,q=0;
    while (p<arr[0].size()&&q<arr[1].size()){
        if (arr[0][p]==arr[1][q]){
            ans+=arr[0][p];
            p++;q++;
        }else if (arr[0][p]>arr[1][q]){
            q++;
        }else p++;
    }string cans;
    for (int i=2;i<n;i++){
        cans="";
        p=0;q=0;
        while (p<arr[i].size()&&q<ans.size()){
            if (arr[i][p]==ans[q]){
                cans+=arr[i][p];
                p++;q++;
            }else if (arr[i][p]>ans[q]){
                q++;
            }else p++;
        }ans=cans;
    }cout<<ans<<endl;
    return 0;
}
