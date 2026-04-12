/* ***********************************************
Author        :Winmer
Created Time  :2018年04月20日 星期五 21时58分44秒
File Name     :vj_lbq_sjjg_a.cpp
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
long long n,k,sum;
int main(){
    while(cin>>n>>k){
    sum=0;
        for(int i=k+1;i<=n;i++){
            sum+=(i-k)*(n/i);
            if(n%i>=k)sum+=(n%i)-k+1;
            if(k==0)sum--;
        }
        //if(k==0){sum-=n/;}
        //sum-=n-k+1;
        //sum+=n-k+1;
        cout<<sum<<endl;
    }
    return 0;
}
