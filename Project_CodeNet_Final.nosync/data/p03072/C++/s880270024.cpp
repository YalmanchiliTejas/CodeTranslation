#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int max;
    int c=1;
    vector<int> Hi(21);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> Hi.at(i);
    }
    max=Hi.at(0);
    for(int i=1;i<N;i++){
        if(max<=Hi.at(i)){
            //t=max;
            max=Hi.at(i);
           // Hi.at(i)=t;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}