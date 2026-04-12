 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool ispal(string a)
{
    long long int n=a.length();
    if(n==1)
        return true;
    else{
    int i=0,j;
    j=n-1;
    while(1)
    {
        if(a[i]!=a[j])
        {
            cout<<i<<" "<<j;
           return false;
        }
        i++,j--;
        if(i==j)
         {
        //     cout<<i<<" ";
             break;
        }
    }
    return true;
}}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  //cin>>t;
  t=1;
  while(t--){
  ll n;
  cin>>n;
  if(n>=30)
  {
      cout<<"Yes";
  }
  else
    cout<<"No";
  }
}