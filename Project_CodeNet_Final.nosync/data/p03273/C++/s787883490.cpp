#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int main(void){
    
    int h, w;
    cin>>h>>w;
    
    vector<int> s(h*w);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin>>c;
            if(c=='#'){
                s[i*w+j]=1;
            }else{
                s[i*w+j]=0;
            }
        }
    }
    
    vector<int> wc, hc;
    
    for(int i=0; i<h; i++){
        int cnt=0;
        for(int j=0; j<w; j++){
            cnt+=s[i*w+j];
        }
        
        if(cnt>0){
            hc.push_back(i);
        }
    }
    
    for(int j=0; j<w; j++){
        int cnt=0;
        for(int i=0; i<h; i++){
            cnt+=s[i*w+j];
        }
        if(cnt>0){
            wc.push_back(j);
        }
    }
    
    for(int i=0; i<hc.size(); i++){
        for(int j=0; j<wc.size(); j++){
            cout<<(s[hc[i]*w+wc[j]]==1?'#':'.');
        }
        cout<<endl;
    }
    cout<<endl;
}
