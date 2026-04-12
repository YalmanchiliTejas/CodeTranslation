#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,max,tmp;
    tmp=-1;
    while (cin>>a>>b) {
        if (a==0&&b==0) {
            break;
        } else {
            max=a+b;
            for (int i=0;i<4;i++) {
                cin>>a>>b;
                if (max<a+b) {
                    max=a+b;
                    tmp=i;
                }
            }
            if (tmp==-1) {
                cout<<"A"<<" "<<max<<endl;
            } else if (tmp==0) {
                cout<<"B"<<" "<<max<<endl;
            } else if (tmp==1) {
                cout<<"C"<<" "<<max<<endl;
            } else if (tmp==2) {
                cout<<"D"<<" "<<max<<endl;
            } else if (tmp==3) {
                cout<<"E"<<" "<<max<<endl;
            }
            tmp=-1;
        }
    }
}

