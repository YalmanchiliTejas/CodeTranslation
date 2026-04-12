/*
Author : Harsh AKA Codula
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(n) for(ll i=0;i<n;++i)


class google
{

    public:
        void run()
        {
            ll a;
            cin>>a;
            int i=0;
            while(a--)
            {
                i+=1;
                cout<<"Cases #"<<i<<": ";
                cout<<"\n";
            }
        }
};
class codechefpattern
{

    public:
        void run()
        {
            ll a;
            cin>>a;
            while(a--)
            {
                cout<<"\n"; 
            } 

        }
};
class other
{
    public:
        void run()
        {
            ll a;
            cin>>a;
            if (a>=30)
            {
                /* code */
                cout<<"Yes";
            }
            else
            {
                cout<<"No";
            }
        }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    google g;
    codechefpattern c;
    other o;

    o.run();
    return 0;
}