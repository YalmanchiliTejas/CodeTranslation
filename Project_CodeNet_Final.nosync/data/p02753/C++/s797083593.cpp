#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <numeric>
#include <iomanip>
#include <limits>

using namespace std;

int main(){

    //int ans=0;
    bool ans=false;

    string a;
    cin>>a;

    if(a=="AAA" || a=="BBB"){
        ans=true;
    }
    //cout<<ans<<endl;
    if(ans){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }

    return 0;
}