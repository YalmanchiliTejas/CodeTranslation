#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> H(N);
    for(int i=0;i<N;i++) cin>>H[i];
    int visible=0;
    int saidai=0;
    for(int i=0;i<N;i++){
        if(H[i]>=saidai){
            visible++;
            saidai=H[i];
        }
    }
    cout<<visible<<endl;
    return 0;
}