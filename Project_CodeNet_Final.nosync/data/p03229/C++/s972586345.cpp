#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
int n;
cin>>n;
ll a[n];
for(int zz=0;zz<n;zz++)
        cin>>a[zz];
sort(a,a+n);
ll l=a[n-1];
ll r=l;            
ll i=0,j=n-2;
ll sum=0;
while(i<j){
        ll li=abs(l-a[i]),ri=abs(r-a[i]);
        ll lj=abs(l-a[j]),rj=abs(r-a[j]);
        if(li>ri||lj>rj){ //left side
                if(li>lj){
                        sum+=li;
                        l=a[i++];
                }else{
                        sum+=lj;
                        l=a[j--];
                }
        }else{
                if(ri>rj){
                        sum+=ri;
                        r=a[i++];
                }else{
                        sum+=rj;
                        r=a[j--];
                }
        }
}
sum+=max(abs(l-a[i]),abs(r-a[i]));
cout<<sum<<endl;
return 0;
}
