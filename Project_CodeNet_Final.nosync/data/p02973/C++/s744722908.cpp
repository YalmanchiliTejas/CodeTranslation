#include <iostream>
using namespace std;
int main(void){
    long long N,i,k,m,M,a;
    cin>>N;
    long long A[N],B[N];
    for(i=0;i<N;i++){
        cin>>A[i];
        B[i]=-1;
    }
    B[0]=A[0];k=0;
    for(i=1;i<N;i++){
        if(A[i]<B[k]+1){
            k++;
            B[k]=A[i];
        }else{
            m=0;M=k;
            while(M-m>1){
                if(A[i]>B[(m+M)/2]){
                    M=(m+M)/2;
                }else{
                    m=(m+M)/2;
                }
            }
            if(A[i]<B[m]+1){
                m++;
            }
            B[m]=A[i];
        }
    }
    k++;
    cout<<k<<endl;
}
