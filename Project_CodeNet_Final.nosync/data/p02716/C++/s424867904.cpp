#include <bits/stdc++.h>
using namespace std;

int M = pow(10,5)*2;

long long int max_ar(long long int *s,int len){
    long long int mx  = s[0];
    for(int i=0;i<len;i++){
        if(s[i]>mx){mx=s[i];}
    }
    return mx;
}

long long int solve(int *a,int head,int tail,int k){
    int len = tail - head;
    if(len<=0 || k==0){
        
        return 0;}
    if(k==1){
        long long int mx = a[head];
        for(int i=head;i<tail;i++){
            if(a[i]>mx){mx = a[i];}
        }
        return mx;
    }
    else if(k*2 > len){
        long long int sum =0;
        int i = head;
        while(i<tail){
            sum += a[i];
            i +=2;

        }
        return sum;
    }
    else {
        int m = len/2;
        int l = k/2;
        if(len%2==0){
            if(k%2==0){
                long long int s1[3];
                s1[0] = a[head+m-1]+solve(a,head,head+m-2,l-1)+solve(a,head+m+1,tail,l);
                s1[1] = a[head+m]+solve(a,head,head+m-1,l)+solve(a,head+m+2,tail,l-1); 
                s1[2] = solve(a,head,head+m-1,l)+solve(a,head+m+1,tail,l);
                return max_ar(s1,3);
            }
            else{
                long long int s2[2];
                s2[0]=a[head+m-1]+solve(a,head,head+m-2,l)+solve(a,head+m+1,tail,l);
                s2[1]=a[head+m]+solve(a,head,head+m-1,l)+solve(a,head+m+2,tail,l);
                return max_ar(s2,2);
            }
            
        }
        else{
            if(k%2==0){
                long long int s3[4];
                s3[0] = a[head+m] + solve(a,head,head+m-1,l) + solve(a,head+m+2,tail,l-1);
                s3[1] = a[head+m] + solve(a,head,head+m-1,l-1) + solve(a,head+m+2,tail,l);
                s3[2] = a[head+m-1] + solve(a,head,head+m-2,l-1) + solve(a,head+m+1,tail,l);
                s3[3] = a[head+m+1] + solve(a,head,head+m,l) + solve(a,head+m+3,tail,l-1);
                return max_ar(s3,4);
            }
            else{
                long long int s4[5];
                s4[0]= a[head+m] + solve(a,head,head+m-1,l)+solve(a,head+m+2,tail,l);
                s4[1]= a[head+m-1]+solve(a,head,head+m-2,l)+solve(a,head+m+1,tail,l);
                s4[2]= a[head+m-1]+solve(a,head,head+m-2,l-1)+solve(a,head+m+1,tail,l+1);
                s4[3]= a[head+m+1]+solve(a,head,head+m,l)+solve(a,head+m+3,tail,l);
                s4[4]= a[head+m+1]+solve(a,head,head+m,l+1)+solve(a,head+m+3,tail,l-1);
                return max_ar(s4,5);

            }
          
        }
    }

}


int main(){
    int N;
    int A[M];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }


    cout << solve(A,0,N,N/2) << endl;


    return 0;
}