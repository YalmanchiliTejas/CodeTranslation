#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll MIN(ll num1,ll num2){
    return num1<num2?num1:num2;
}

int main(){

    while(1){
        int N;
        vector<int> V;
        cin>>N;
        if(N==0)break;
        for(int i=0;i<N;i++){
            int v;
            cin>>v;
            V.push_back(v);
        }
        sort(V.begin(),V.end());
        int sum=0;
        for(int i=1;i<N-1;i++)sum+=V[i];
        cout<<sum/(N-2)<<endl;
    }

    return 0;
}
