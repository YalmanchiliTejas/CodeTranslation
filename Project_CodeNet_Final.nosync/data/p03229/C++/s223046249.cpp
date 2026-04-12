//https://tenka1-2018-beginner.contest.atcoder.jp/tasks/tenka1_2018_c
#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long maxSum(long long a[], long long n){
    sort(a,a+n);
    long long l=a[n-1]; //kiri
    long long r=l;             // kanan
    long long i=0,j=n-2;
    long long sum=0;
    while(i<j){
        long long li=abs(l-a[i]),ri=abs(r-a[i]);
        long long lj=abs(l-a[j]),rj=abs(r-a[j]);
        if(li>ri||lj>rj){ //kiri
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
    sum += max(abs(l-a[i]),abs(r-a[i]));
    return sum;
}

int main(){
    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0; i<n; i++){
        cin >> a[i];
    }
    cout<< maxSum(a,n) <<endl;
}
