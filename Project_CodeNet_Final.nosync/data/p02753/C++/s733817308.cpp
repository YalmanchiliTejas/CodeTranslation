#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
typedef pair<int,int> pii;

int main()
{
    string str;cin>>str;
    for(int i=1;i<3;i++){
        if(str[i]!=str[i-1]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}