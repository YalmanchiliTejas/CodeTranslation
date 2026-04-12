#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int maxSum(int arr[], int n)
{
    int sum = 0;

    sort(arr, arr + n);
    for (int i = 0; i < n/2; i++)
    {
        sum -= (2 * arr[i]);
        sum += (2 * arr[n - i - 1]);
    }

    return sum;
}

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
        //cout<<l<<"---"<<r<<"------"<<i<<"---"<<j<<"----------"<<sum<<endl;
}
sum+=max(abs(l-a[i]),abs(r-a[i]));
cout<<sum<<endl;

}
