#include<bits/stdc++.h>
using namespace std;
#define LL long long int
#define DL double
#define MLL map<LL,LL>::iterator
#define MSL map<string,LL>::iterator
#define MLS map<LL,string>::iterator
#define MSS map<string,string>::iterator
#define MCL map<char,LL>::iterator
#define SL set<LL>::iterator
#define SS set<string>::iterator
#define VL vector<LL>::iterator
#define G getline
#define SZ size()
#define IN insert
#define C clear()
#define B begin()
#define F front()
#define T top()
#define E end()
#define EM empty()
#define V vector
#define Q queue
#define DQ deque
#define PQ priority_queue
#define ST stack
#define FI first
#define SE second
#define PI acos(-1)
#define PS push
#define PP pop()
#define PSF push_front
#define PSB push_back
#define PPF pop_front()
#define PPB pop_back()
#define endl "\n"
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
LL v[3];
int main()
{
    FAST;
    LL n,m,i,j,k,p,q,o,l,s,t,z;
    cin>>n>>m>>o>>p>>q;
    k=0;
    if(n+m>o*2)
    {
        z=min(p,q);
        k+=(z*o*2);
        if(p>q)
        {
            l=p-q;
            if(l*n<=l*o*2)
            {
                k+=(l*n);
            }
            else
            {
                k+=(l*o*2);

            }
        }
        else
        {
            l=q-p;
            if(l*m<=l*o*2)
            {
                k+=(l*m);
            }
            else
            {
                k+=(l*o*2);

            }
        }

    }
    else
    {
        k+=(p*n);
        k+=(q*m);
    }
    cout<<k<<endl;

    return 0;
}
