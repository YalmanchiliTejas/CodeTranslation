#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<int>vec(12);
    for(int i=0;i<12;i++)cin>>vec[i];
    sort(vec.begin(),vec.end());
    if(vec[0]==vec[1]&&vec[1]==vec[2]&&vec[2]==vec[3]&&vec[4]==vec[5]&&vec[5]==vec[6]&&vec[6]==vec[7]&&vec[8]==vec[9]&&vec[9]==vec[10]&&vec[10]==vec[11])cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
