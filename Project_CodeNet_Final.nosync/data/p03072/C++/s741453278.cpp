#include "bits/stdc++.h"

using namespace std;

int main() {
    /*int a,b,h,s;
    cin >> a >> b >> h;
    
    s=(a+b)*h/2;
    
    cout << s << endl;*/
    
    /*int N,A,B;
    cin >> N >> A;
    B=N*N-A;
    
    cout << B << endl;*/
    
   /* int A,B,C,D,s1,s2;
    cin >> A >> B >> C >> D;
    
    s1=A*B;
    s2=C*D;
    
    if(s1>s2){
        cout << s1 << endl;
    }
    else if(s1<s2){
        cout << s2 << endl;
    }
    else{
        cout << s1 << endl;
    }*/
    
   /* int a,b,c,s;
    cin >> a >> b >> c;
    
    s=0;
    if(a!=b){
        s=s+1;
    }
    if(a!=c){
        s=s+1;
    }
    if(b!=c){
        s=s+1;
    }
    if(a==b&&a==c&&b==c){
        s++;
    }
    cout << s << endl;*/
    
    /*int N,K,X,Y,s;
    cin >> N >> K >> X >> Y;
    
    if(N>K){
        s=K*X+Y*(N-K);
    }
    
    
    
    else if(N<=K){
        s=N*X;
    }
    
    cout << s << endl;*/
    
   /* long long N,A[200000],B[200000],s;
    cin >> N;
    
    int i = 0;
    while(i<N){
        cin >> A[i] >> B[i];
        i++;
    }
    
    i=0;
    while(i
    <N){
        s=A[i]*B[i];
        i++;
        cout << s << endl;
    }*/
    
    /* N,A,B,ans;
    cin >> N;
    
    for(int i=0;i<N;i++){
        
    }*/

    /*int N,L,maxL,sumL;
    cin >> N;
    
    maxL=0;
    sumL=0;
    for(int i=0;i<N; i++){
        cin >> L;
        maxL=max(L,maxL);
        sumL+=L;
    }
    if(maxL<sumL-maxL){
        cout << "Yes" << endl;
    }
    else if(maxL>=sumL-maxL){
        cout << "No" << endl;
    }*/
    
    int N,H;
    cin >> N;
    
    int u=0;
    int maxh=0;
    for(int i=0; i<N;i++){
        cin >> H;
        if(H>=maxh){
            u++;
        }
    
        maxh=max(maxh,H);
        
    }
        
    cout << u << endl;
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}