
/*Hey, What's up?*/

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
multiset<long long>st;
multiset<long long>::iterator it;
int main()
{
    fastio;
    long long a=0,b=0,c,d,e,f=0,l,g,m,n,k,i,j,t,p,q;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a;
        if(st.size()==0)st.insert(a);
        else{
            it=st.lower_bound(a);
            if(it==st.begin()){
                st.insert(a);
            }
            else{
                it--;
                st.erase(it);
                st.insert(a);
            }
        }
    }
    cout<<st.size();

    return 0;
}
