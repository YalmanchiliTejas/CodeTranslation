#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
ll a[200005];
const int mod=1e9+7;
void shit(){
    string s,t;
    int max_=-1;
    cin>>s>>t;
    for(int i=0;i<s.size();i++)
    {
        int temp=0;
        int ii=i;
        //cout<<ii<<" sa"<<endl;
        for(int j=0;j<t.size();j++)
        {
            //cout<<j<<endl;
            if(ii<s.size()&&s[ii]==t[j])
            {
                //cout<<ii<<" "<<j<<" ";
                //cout<<temp<<endl;
                temp++;
                ii++;
            }
            else
            {
                if(temp>max_&&j-temp<=ii-temp&&t.size()-j<=s.size()-ii)
                {
                    max_=temp;
                }
                temp=0;
            }
        }
        if(temp>max_&&t.size()-temp<=ii-temp&&0<=s.size()-ii)
        {
            max_=temp;
        }
    }
    cout<<t.size()-max_;
}

void slove(){
    ll n;
    cin>>n;
    ll sum=0;
    ll res=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum=(sum+a[i]%mod)%mod;
    }
    for(int i=0;i<n;i++)
    {
        res=((sum-a[i]+mod)%mod*a[i]%mod+res)%mod;
    }
    if(res%2==0)
        cout<<res/2;
    else
        cout<<((res+mod)/2)%mod;
}

int main() {
    int _=1;
//    cin>>_;
    while (_--){
        slove();
    }
    return 0;
}