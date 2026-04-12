#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
    int e[12];
    for(int i=0;i<12;i++){
        cin >> e[i];
    }
    sort(e,e+12);
    int cnt=0;
    if(e[0]==e[1]&&e[0]==e[2]&&e[0]==e[3]){
        cnt++;
    }
    if(e[4]==e[5]&&e[4]==e[6]&&e[4]==e[7]){
        cnt++;
    }
    if(e[8]==e[9]&&e[8]==e[10]&&e[8]==e[11]){
        cnt++;
    }
    if(cnt==3){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
    
    return 0;
}

