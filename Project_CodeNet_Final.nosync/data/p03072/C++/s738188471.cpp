#include<iostream>
#include<vector>
using namespace std;

int main(){
        int N;
        cin>>N;
        vector<int> H(20);
        for(int i;i<N;i++){
                cin>>H.at(i);
}

        int answer=0;
        bool flag=true;

        for(int i=0;i<N;i++){
          flag=true;
                for(int j=0;j<i;j++){
                        if(H.at(j)<=H.at(i)){
                                continue;
                        }else{
                                flag=false;
                        }
                }
  if(flag){
                        answer++;
                }
        }
        cout<<answer<<endl;
        return 0;
}
