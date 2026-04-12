#include <iostream>
using namespace std;

int main() {
    int h,w,c=0;
    cin>>h>>w;
    for(int i=0;i<h;i++){
        string a;
        cin>>a;
        for(int j=0;j<w;j++){
            if(a[j]=='#')c++;
        }
    }
    if(c==h+w-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
	return 0;
}