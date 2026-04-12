#include<bits/stdc++.h>
using namespace std;

int main(){

    int h,w;
    cin>>h>>w;

    vector<string> a(h);

    for(int i=0;i<h;i++) cin>>a.at(i);

    vector<bool> tate(h,false),yoko(w,false);

    for(int i=0;i<h;i++){

        for(int j=0;j<w;j++){

            if(a.at(i).at(j)=='#'){
                tate.at(i)=true;
                yoko.at(j)=true;
            }

        }

    }

    bool flag=false;

    for(int i=0;i<h;i++){

        flag=false;
        for(int j=0;j<w;j++){

            if(tate.at(i)==true&&yoko.at(j)==true){

                cout<<a.at(i).at(j);
                flag=true;
            }

        }

        if(flag==true) cout<<endl;

    }






    return 0;
}