#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    char str[33];
    vector<char> rh={'y','u','i','o','p','h','j','k','l','n','m'};
    while(1){
        cin >> str;
        if(str[0]=='#') break;
        
        int count=0;
        bool right;
        for(int i=0; str[i]!=0; i++){
            auto itr = find(rh.begin(),rh.end(),str[i]);
            bool hand= (itr!= rh.end())?true:false;
            if(i==0)right=hand;
            if(right!=hand){
                count++;
                right=hand;
            }
        }
        cout << count << endl;
    }    
    return 0;
}