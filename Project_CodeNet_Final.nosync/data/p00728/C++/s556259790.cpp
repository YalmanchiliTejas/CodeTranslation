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

int main(){
    int n,tmp,maxN,minN;
    vector<int> ans;
    int tmpd;
    string num1,num2;
    while(1){
        cin>>n;
        if(n==0)break;
        tmpd=0;maxN=0;minN=1001;
        for(int i=0;i<n;i++){
            cin>>tmp;
            maxN = max(maxN,tmp);
            minN = min(minN,tmp);
            tmpd += tmp;
        }
        ans.push_back((tmpd-minN-maxN)/(n-2));

    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
