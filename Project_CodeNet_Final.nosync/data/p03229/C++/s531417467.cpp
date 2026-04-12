#include <iostream>
#include<algorithm>
using namespace std;
int n;
int a[100000+5],b[2];
unsigned long long sum=0;
unsigned long long sums=0;
int main(){
    scanf("%d",&n);
    if(n==1){
        cout<<"0\n";
        return 0;
    }

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int l=1,r=n-1;

    sum=abs(a[0]-a[n-1])+abs(a[0]-a[n-2]);
    b[0]=a[n-1];b[1]=a[n-2];
    bool f=0;//jiang yao fang min
    while(r-2>=l){
        if(f){
            sum+=max(abs(a[r]-b[0])+abs(a[r-1]-b[1]),abs(a[r-1]-b[0])+abs(a[r]-b[1]));
            b[0]=a[r]; b[1]=a[r-1];
            l+=2;

        }
        else{
            sum+=max(abs(a[l]-b[0])+abs(a[l+1]-b[1]),abs(a[l+1]-b[0])+abs(a[l]-b[1]));
            b[0]=a[l]; b[1]=a[l+1];
            r-=2;
        }
            f=1-f;

    }
    l=0,r=n-2;
    f=1;
    sums=abs(a[n-1]-a[0])+abs(a[n-1]-a[1]);
    b[0]=a[0];b[1]=a[1];
    while(r-2>=l){
        if(f){
            sums+=max(abs(a[r]-b[0])+abs(a[r-1]-b[1]),abs(a[r-1]-b[0])+abs(a[r]-b[1]));
            b[0]=a[r]; b[1]=a[r-1];
            l+=2;

        }
        else{
            sums+=max(abs(a[l]-b[0])+abs(a[l+1]-b[1]),abs(a[l+1]-b[0])+abs(a[l]-b[1]));
            b[0]=a[l]; b[1]=a[l+1];
            r-=2;
        }
            f=1-f;

    }
    cout<<max(sums,sum)<<'\n';


}//6 3 1 4 1 5 9
//1 1 3 4 5 9
//    1 9 1 5 3
//2+6+8+5+5+3
