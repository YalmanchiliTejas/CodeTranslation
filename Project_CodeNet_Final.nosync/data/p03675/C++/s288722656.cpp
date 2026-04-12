#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mod 1000000007
using namespace std;
const int N=1234567;
int A[N];

int main()
{
ios_base::sync_with_stdio(false);


int n;
cin>>n;

vi odd,even;

for(int i=1;i<=n;i++)
{
    cin>>A[i];
    if(i%2 ==0)
        even.pb(A[i]);
    else
        odd.pb(A[i]);

}


if(n%2 ==0)
{
    reverse(even.begin(),even.end());
    for(int i=0;i<even.size();i++)
        cout<<even[i]<<" ";
    for(int i=0;i<odd.size();i++)
        cout<<odd[i]<<" ";
}
else
{
        reverse(odd.begin(),odd.end());
    for(int i=0;i<odd.size();i++)
        cout<<odd[i]<<" ";
    for(int i=0;i<even.size();i++)
        cout<<even[i]<<" ";
}

return 0;
}
