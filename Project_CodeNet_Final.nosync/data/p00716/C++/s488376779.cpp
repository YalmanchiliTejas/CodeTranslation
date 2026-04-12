#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <utility>
#include <string>

using namespace std;

typedef long long int ll; 
typedef pair<int,int> Pii;



int comp(int initV,int years,double inter,int fee){
    int sum=0;
    sum = initV;
    for(int i=0;i<years;i++){
        sum = sum*(1+inter) - fee;
    }
    return sum;
}

int simp(int initV,int years,double inter,int fee){
    int A,interSum;
    A=initV;interSum=0;
    for(int i=0;i<years;i++){
        interSum+=A*inter;
        A-=fee;
    }
    return interSum+A;
}


int main(){
    int n,m,tmp,years;
    int initV;
    vector<int> ans;

    cin>>m;

    for(int i=0;i<m;i++){
        vector<int> tmpA;
        cin>>initV>>years>>n;
        for(int i=0;i<n;i++){
            int mode,fee;
            double inter;
            cin>>mode>>inter>>fee;
            if(mode == 0){
                tmp = simp(initV,years,inter,fee);
                tmpA.push_back(tmp);
            }else{
                tmp = comp(initV,years,inter,fee);
                tmpA.push_back(tmp);
            }
        }
        int max = *max_element(tmpA.begin(),tmpA.end());
        ans.push_back(max);
    }
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
    return 0;
}
