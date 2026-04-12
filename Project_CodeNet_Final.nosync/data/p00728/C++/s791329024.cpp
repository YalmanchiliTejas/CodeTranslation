#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0)return 0;
        vector<int> V(n);
        for(int i=0;i<n;i++)cin>>V[i];
        sort(V.begin(),V.end());
        int sum=0;
        for(int i=1;i<n-1;i++)sum+=V[i];
        cout<<sum/(n-2)<<endl;
    }
}