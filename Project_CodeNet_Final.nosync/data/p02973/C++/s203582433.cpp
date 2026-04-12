
    
    
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,m,j,k,l,o,p;
    cin>>n;
    vector<int>outputvec,v;
    for(i=0;i<n;i++)
    {
        cin>>l;
        v.push_back(l);
        if(i==0)
        {
            outputvec.push_back(l);
        }
        else
        {
            int V=-1;
            int I=0;
            int J=outputvec.size()-1;
            while(I<=J)
            {
                m=(I+J)/2;
                if(outputvec[m] < l)
                {
                    V=m;
                    I=m+1;
                }
                else
                {
                    if(outputvec[m] >= l)
                    {
                        J=m-1;
                    }
                }
            }
            if(V==-1)
            {
                auto it = lower_bound(outputvec.begin(),outputvec.end(),l)-outputvec.begin();
                outputvec.insert(outputvec.begin()+it,l);
            //    cout<<Y<<endl;
               // outputvec.insert(v.begin()+Y,l);
            }
            else
            {
                outputvec[V]=l;
            }
        }
    }
    cout<<outputvec.size();
}