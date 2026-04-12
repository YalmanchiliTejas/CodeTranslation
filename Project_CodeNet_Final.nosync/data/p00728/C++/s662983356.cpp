#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n!=0){
        int s, sum = 0, large = 0, small = 1000;
        for(int i=0;i<n;++i){
            cin >> s;
            sum+=s;
            if(large<s) large=s;
            if(small>s) small=s;
        }

        cout<<(sum-large-small)/(n-2)<<"\n";

        cin >> n;
    }
}