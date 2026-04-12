#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<long> A;
    long ansarr[N];
    long ansarr1[N], ansarr2[N];
    long tmp;
    long ans=0;
    long ans1=0;
    for(int i=0;i<N;++i){
        cin>>tmp;
        A.push_back(tmp);
    }

    sort(A.begin(), A.end());

    if (N%2==0){
        for(int i=0;i<N/2;++i){
            if(i%2==0){
                ansarr[N/2-i-1] = A[i];
                ansarr[N/2+i] = A[A.size()-i-1];
            }
            else{
                ansarr[N/2-i-1] = A[A.size()-i-1];
                ansarr[N/2+i] = A[i];
            }
        }
        for(int i=0;i<N-1;++i){
            ans += abs(ansarr[i+1] - ansarr[i]);
        }
        cout<<ans<<endl;
    }
    else {
        for(int i=0;i<(N-1)/2;++i){
            if(i%2==0){
                ansarr1[(N-1)/2+i] = A[A.size()-i-1];
                ansarr1[(N-1)/2-i-1] = A[i];
                ansarr2[(N-1)/2+i+1] = A[A.size()-i-1];
                ansarr2[(N-1)/2-i] = A[i];
            }
            else {
                ansarr1[(N-1)/2+i] = A[i];
                ansarr1[(N-1)/2-i-1] = A[A.size()-i-1];
                ansarr2[(N-1)/2+i+1] = A[i];
                ansarr2[(N-1)/2-i] = A[A.size()-i-1];
            }
        }
        ansarr1[N-1] = A[(A.size()-1)/2];
        ansarr2[0] = A[(A.size()-1)/2];
        for(int i=0;i<N-1;++i){
            ans += abs(ansarr1[i+1] - ansarr1[i]);
            ans1 += abs(ansarr2[i+1] - ansarr2[i]);
        }
        if(ans>ans1){
            cout<<ans<<endl;
        }
        else{
            cout<<ans1<<endl;
        }
    }
}
