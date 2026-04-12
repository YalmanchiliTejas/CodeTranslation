#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long
int looktable[4000][4000];
int optimal(int arr[],int i,int j)
{
    if(i==j)
        return arr[i];
    if(i+1==j)
        return max(arr[i],arr[j]);
    if(looktable[i][j]==0)
    {
     int left=arr[i]+min(optimal(arr,i+2,j),optimal(arr,i+1,j-1));
     int right=arr[j]+min(optimal(arr,i+1,j-1),optimal(arr,i,j-2));
     looktable[i][j]=max(left,right);
    }
    return looktable[i][j];

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n;
   cin>>n;
    int arr[n],su=0;
   for(int i=0;i<n;i++){

     cin>>arr[i];
     su+=arr[i];
   }
   memset(looktable,0,sizeof(looktable));
    int x=optimal(arr,0,n-1);
   // cout<<x<<" ";
    int y=su-x ;
   // cout<<y<<" ";
    cout<<x-y;
    return 0;
}
