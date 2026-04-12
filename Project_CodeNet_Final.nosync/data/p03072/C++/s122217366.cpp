#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin>>N;
    int h;
    int m=0;
    cin>>m;
    int c=1;
    for(int i=1; i<N; ++i){
        cin>>h;
        if(m<=h){
            c++;
            m=h;
        }
    }
    cout<<c<<endl;

    return 0;
}