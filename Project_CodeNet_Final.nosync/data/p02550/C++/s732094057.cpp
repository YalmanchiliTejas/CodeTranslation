#include<iostream>
#include<vector>
#include<map>
using namespace std;

long long N,X,M,ans;
int main(){
    cin>>N>>X>>M;

    map<int,int>m;

    vector<long long>A(2);
    A[0]=0LL;
    A[1]=X;

    for(int i=1;i<=N;i++){
        //cout<<"A"<<i<<"="<<A[i]<<endl;

        if(m[A[i]]){
            //cout<<"used:"<<i<<" "<<m[A[i]]<<endl;

            long long l=m[A[i]],r=i,loop_size=r-l,loop_val=0LL;
            //cout<<"size"<<loop_size<<endl;
            for(int j=1;j<l;j++){
                ans+=A[j];
            }
            for(int j=l;j<r;j++){
                loop_val+=A[j];
            }
            //cout<<loop_val<<endl;
            ans+=loop_val*((N-(l-1))/loop_size);

            //cout<<"loop num"<<((N-l)/loop_size)<<endl;

            for(int j=0;j<((N-(l-1))%loop_size);j++){
                ans+=A[l+j];
            }
            cout<<ans<<endl;
            return 0;
        }

        m[A[i]]=i;
        A.push_back(A[i]*A[i]);
        A[i+1]%=M;

    }
    for(int i=1;i<=N;i++)ans+=A[i];
    cout<<ans<<endl;
    return 0;
}