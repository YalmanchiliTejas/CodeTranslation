#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>
#include<cstdio>
#include<iomanip>


using namespace std;
using ll = long long int; 

int main(void){

    string x;
    cin>>x;

    if(x[0]==x[1] && x[1]==x[2]){
        cout<<"No"<<endl;
        return 0;
    }

    cout<<"Yes" <<endl;
    return 0;
}