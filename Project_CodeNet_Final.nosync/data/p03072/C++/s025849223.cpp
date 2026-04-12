#include<iostream>
#include<vector>
using namespace std;

int oceanview(int N,vector<int> H){
    int count=1;
    int i,j;
    for(i=1;i < N;i++){
        for(j=i-1;j>-1;j--){
            //cout<< i << " " << H[i] << " " << j << " " <<H[j] << endl;
            if(H[i]>=H[j]){
                continue;
            }
            else break;
        }
        if(j==-1) count++;
      // cout<< count << endl;
    }
    return count;
}

int main(){
    int N;
    cin >> N;
    
    vector<int> H(N,0);
    for(int i=0;i<N;i++)
        cin >> H[i];
    
    cout << oceanview(N,H) << endl;
    return 0;
}