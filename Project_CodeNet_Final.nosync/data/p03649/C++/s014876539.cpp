#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector <long long>a(N);
    for(int i=0 ; i<N ; i++){
        cin>>a[i];
    }

    long long sum=0;
    long long s=0;
    while(1){
        for(int i=0 ; i<N ; i++){
            s=(long long)(a[i]/N);
            a[i]=a[i]%N;
            sum+=s;
            if(s==0)continue;
            for(int j=0 ; j<N ; j++){
                if(i==j)continue;
                a[j]+=s;
            }
        }
        sort(a.begin(),a.end());
        if(a[N-1]<N)break;
    }
    cout<<sum<<endl;
    return 0;
}
