#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
 {
     int n;
     cin>>n;
     ll a[2*100000];
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }
    sort(a,a+n);
    int l=a[n-1]; //left
    int r=l;             // right
int i=0,j=n-2;
long long int sum=0;
while(i<j){
        int li=abs(l-a[i]),ri=abs(r-a[i]);
        int lj=abs(l-a[j]),rj=abs(r-a[j]);
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

}
