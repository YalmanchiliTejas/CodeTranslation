#include <bits/stdc++.h>

using namespace std;


int main(void) {
    string S;
    int count_A=0,count_B=0;

    cin>>S;

    for(int i=0;i<S.size();i++){
        if(S[i] == 'A'){
            count_A++;
        }else{
            count_B++;
        }
    }

    if(count_B == 0 || count_A == 0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }




	return 0;
}