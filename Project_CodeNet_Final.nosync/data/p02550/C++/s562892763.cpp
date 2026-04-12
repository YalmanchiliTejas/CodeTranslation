#include<bits/stdc++.h>
using namespace std;

long long ara[100009],tra[300009];

int main()
{


        long long n,m,a,b,c,d,e,f,g,h,p,q,r,fr,sc,tr,sz=0,tz,i,j,k,mx=LLONG_MIN,mn=LLONG_MAX;
        long long x=0,y=0,z=0,cnt=0,res=0,ans=0,sum=0; long long flg=0,flag=1,na=0,as=1;
        vector<long long>u,v,w; vector< pair<long long,long long> >vct; vector<string>vst;
        set<long long>st,nt,tt; map<long long,long long>mp,nq,qr; string str,ttr,ntr;

        scanf("%lld %lld %lld",&n,&d,&m);

        f=d; ara[f]++; ans=f; if(n==1){  flg=1; }

        if(flg==0)
        {

            for(i=2;i<=400007;i++)
            {
                b=f*f;

                c=b%m; ara[c]++; if(ara[c]==3){  z=i; break;   }

                ans=ans+c; if(i==n){  flg=1; break;  }

                if(ara[c]==2 && x==0){  x=i;  }

                if(x!=0)
                {
                    sum=sum+c; y++;  tra[y]=sum;

                }



                f=c;

            }

        }


        if(flg==0)
        {
            fr=z-x; sc=n-z; sc++;

            tr=sc/fr; p=tra[y]*tr; ans=ans+p;

            h=sc%fr; ans=ans+tra[h];

        }



        printf("%lld\n",ans);







    return 0;
}



