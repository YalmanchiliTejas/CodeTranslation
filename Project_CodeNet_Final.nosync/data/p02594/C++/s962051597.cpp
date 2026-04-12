#include<bits/stdc++.h>
#define endl "\n"
#define ll long long
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mo 1000000007
#define MA 10e17
 ll int val[1000004]={0};
using namespace std;
//Conditional Operator (condition?true part:false part) eg : cout<<(y<=3?"YES":"NO")<<endl;
//string s(3,'1');
ll getmul(ll n){ll int k{0};while(n>0){k+=n%10;n=n/10;}return k;}//Sum OF n DIGITS
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{1};
  //  cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x>=30)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
 return 0;
}