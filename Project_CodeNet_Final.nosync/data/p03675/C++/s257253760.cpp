#include <iostream>
#include <vector>
using namespace std;

int main(){
        int n;
        cin>>n;
        vector<int> be, bo;
        for(int i=0; i<n; i++){
                int a;
                cin>>a;
                if(i%2==0){
                        bo.push_back(a);
                }
                else{
                        be.push_back(a);
                }
        }
        vector<int> f, s;
        if(n%2==0){
                f=be;
                s=bo;
        }
        else{
                f=bo;
                s=be;
        }


        for(auto it=f.rbegin(); it!=f.rend(); it++){
                if(it!=f.rbegin()) cout<<" ";
                cout<<(*it);
        }
        for(auto it=s.begin(); it!=s.end(); it++){
                cout<<" "<<(*it);
        }

        return 0;
}
