#include <iostream>
#include <string>
using namespace std;
int main(void){
    int h,w;
    cin >>h>>w;
    string s[h],ww="";
    for(int i=0;i<w;i++){
        ww+=".";
    }
    for(int i=0;i<h;i++){
        cin>>s[i];
        if(s[i]==ww){
            i--;
            h--;
        }
    }
    
    for(int i=0;i<w;i++){
        bool b =true;
        for(int j=0;j<h;j++){
            if(s[j][i]=='#'){
                j=h;
                b=false;
                
            }
        }
        if(b){
            for(int j=0;j<h;j++){
                s[j] = s[j].substr(0,i)+s[j].substr(i+1);
            }
            i--;
            w--;
        }
    }
    
    
    
    for(int i=0;i<h;i++){
        cout<<s[i]<<endl;
    }
    
}
