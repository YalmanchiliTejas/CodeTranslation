#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h.at(i);
    }
    int ans=1;
    int saidai=h.at(0);
    for(int i=1;i<n;i++){
        if(h.at(i)>=saidai){
            ans++;
        }
        saidai=max(saidai,h.at(i));
    }
    cout<<ans<<endl;
}
