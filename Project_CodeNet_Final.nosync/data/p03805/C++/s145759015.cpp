#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<pair<int,int>> ab(M);
    
    for(int i=0;i<M;i++){
        cin >> ab.at(i).first >> ab.at(i).second;
        ab.at(i).first--;
        ab.at(i).second--;
    } 

    vector<int> ans(N);
    for(int i=0;i<N;i++){
        ans.at(i)=i;
    }
    int count = 0;
    do{
        for(int i=0;i<N-1;i++){
            bool flag = false;
            for(int j=0;j<M;j++){
                if((ans.at(i)==ab.at(j).first&&ans.at(i+1)==ab.at(j).second)||(ans.at(i+1)==ab.at(j).first&&ans.at(i)==ab.at(j).second)){
                    flag =true;
                    break;
                }
            }
            if(!flag) break;
            if(i==N-2) count++;
        }
    }while(next_permutation(ans.begin()+1,ans.end()));

    cout << count << endl;
}