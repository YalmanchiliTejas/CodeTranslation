#include<bits/stdc++.h>
//#include<atcoder/all>

using namespace std;
//using namespace atcoder;


int main(){
    long long N,X,M;
    cin>>N>>X>>M;
    set<long long> s;
    long long A=X;
    s.insert(A);
    long long sum=A;
    N--;
    while(N>0){
        A=A*A%M;
        if(s.find(A)!=s.end()){
            long long sum2=A;
            long long c=1;
            long long A2=A;
            while(1){
                A2=A2*A2%M;
                if(A2==A) break;
                c++;
                sum2+=A2;
                //cout<<c<<","<<sum2<<endl;
            }
            sum+=sum2*(N/c);
            //cout<<N<<","<<c<<","<<sum2<<endl;
            N%=c;
            s.clear();
            if(N==0) break;
        }
        s.insert(A);
        sum+=A;
        //cout<<A<<endl;
        N--;
    }
    cout<<sum<<endl;
}
