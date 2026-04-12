#include <iostream>
#include <string>

using namespace std;


int main(void){
    int n;
    cin>>n;
    
    string s[n];
    int ss=1e9;
    int b;
    for(int i=0;i<n;i++){
        cin>>s[i];
        //cout<<s[i]<<endl;
        int a=s[i].size();
        if(a<ss){
            ss=a;
            b=i;
        }
    }
    string ans;
    int c=1;
    for(int i=0;i<s[b].size();i++){
        for(int j=0;j<n;j++){
            if(s[j].find(s[b][i])==std::string::npos){
                //cout<<s[j]<<" "<<s[b][i]<<endl;
                c=1;
                break;
            }else{
                if(b!=j){
                    int p=s[j].find(s[b][i]);
                    s[j][p]='1';
                    //cout<<s[j]<<endl;
                }
                c=0;
            }
        }
        if(c==0){
            ans+=s[b][i];
            c=1;
        }
        //cout<<endl;
    }
    
    if(ans.size()==0){
        cout<<""<<endl;
        return 0;
    }
    
    
    for(int i=0;i<ans.size()-1;i++){
        for(int j=ans.size()-1;j>i;j--){
            if(ans[j-1]>ans[j]){
                char tmp=ans[j];
                ans[j]=ans[j-1];
                ans[j-1]=tmp;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
