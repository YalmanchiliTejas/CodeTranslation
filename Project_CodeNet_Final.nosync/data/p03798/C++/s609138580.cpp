#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

const int MAX=100005;
char T[MAX];
char A[MAX],B[MAX],C[MAX],D[MAX];

int main(){
    
    int N;cin>>N;
    for(int i=0;i<N;i++){
        char a;cin>>a;
        T[i]=a;
    }
    A[0]='S';A[1]='S';
    B[0]='S';B[1]='W';
    C[0]='W';C[1]='S';
    D[0]='W';D[1]='W';
    for(int i=1;i<N;i++){
        if(T[i]=='o'){
            if(A[i]=='S') A[i+1]=A[i-1];
            else if(A[i-1]=='S') A[i+1]='W';
            else A[i+1]='S';
            if(B[i]=='S') B[i+1]=B[i-1];
            else if(B[i-1]=='S') B[i+1]='W';
            else B[i+1]='S';
            if(C[i]=='S') C[i+1]=C[i-1];
            else if(C[i-1]=='S') C[i+1]='W';
            else C[i+1]='S';
            if(D[i]=='S') D[i+1]=D[i-1];
            else if(D[i-1]=='S') D[i+1]='W';
            else D[i+1]='S';
        }else{
            if(A[i]=='W') A[i+1]=A[i-1];
            else if(A[i-1]=='S') A[i+1]='W';
            else A[i+1]='S';
            if(B[i]=='W') B[i+1]=B[i-1];
            else if(B[i-1]=='S') B[i+1]='W';
            else B[i+1]='S';
            if(C[i]=='W') C[i+1]=C[i-1];
            else if(C[i-1]=='S') C[i+1]='W';
            else C[i+1]='S';
            if(D[i]=='W') D[i+1]=D[i-1];
            else if(D[i-1]=='S') D[i+1]='W';
            else D[i+1]='S';
        }
    }
    if(T[0]=='o'){
        if(A[1]==A[N-1]&&A[0]==A[N]){
            for(int i=0;i<N;i++){
                cout<<A[i];
            }
        }else if(B[1]==B[N-1]&&B[0]==B[N]){
            for(int i=0;i<N;i++){
                cout<<B[i];
            }
        }else if(C[1]!=C[N-1]&&C[0]==C[N]){
            for(int i=0;i<N;i++){
                cout<<C[i];
            }
        }else if(D[1]!=D[N-1]&&D[0]==D[N]){
            for(int i=0;i<N;i++){
                cout<<D[i];
            }
        }else cout<<-1;
    }else{
        if(A[1]!=A[N-1]&&A[0]==A[N]){
            for(int i=0;i<N;i++){
                cout<<A[i];
            }
        }else if(B[1]!=B[N-1]&&B[0]==B[N]){
            for(int i=0;i<N;i++){
                cout<<B[i];
            }
        }else if(C[1]==C[N-1]&&C[0]==C[N]){
            for(int i=0;i<N;i++){
                cout<<C[i];
            }
        }else if(D[1]==D[N-1]&&D[0]==D[N]){
            for(int i=0;i<N;i++){
                cout<<D[i];
            }
        }else cout<<-1;
        
    }
    cout<<endl;
    
}
