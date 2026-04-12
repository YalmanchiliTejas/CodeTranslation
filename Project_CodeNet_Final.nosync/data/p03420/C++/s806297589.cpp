#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define pb push_back
#define pi 2*acos(0.0)
#define db double
#define mk make_pair

int main()
{
    ll i,j,k,n,tc,q,x,y,z,t,v,d,c,p,m;
    ///////////////////////////////////////////
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ////////////////////////////////////////////

    cin>>n>>k;
    {
        if(k==0)
        {
            cout<<n*n<<endl;
            return 0;
        }
        x=n-k;
        y=(x+1)*x/2;
        for(i=k; i<n; i++)
        {
            q=n-i;
            x=q;
            p=1;
            while(q>=i+1)
            {
                d=q/(p+1);
                if(d>=i)
                {
                    y+=(x-d)*p;
                }
                else
                {
                    y+=(x-i)*p;
                    break;
                }
                p++;
                x=d;
            }
        }
        cout<<y<<endl;
    }
    return 0;
}
