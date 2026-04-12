#include<bits/stdc++.h>
#define slowanddetermined ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


int main()
{
    slowanddetermined

    string s;
    cin>>s;
    set<char>sr;
    for(int i=0;i<3;i++){
        sr.insert(s[i]);
    }
    if(sr.size()>1){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }




    return 0;

}
