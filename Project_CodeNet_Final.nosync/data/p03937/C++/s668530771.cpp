#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int H,W;
    cin >> H >> W;
    
    string S[H];
    
    for(int i = 0; i < H;i++)cin >> S[i];
    
    //cout << S[0][0]<<endl;
    int F[H][W];
    int cont = 0;
    for(int i = 0; i < H;i++){
        for(int j = 0; j < W;j++){
            F[i][j]=0;
            if(S[i][j]=='#')cont++;
        }
    }
    
    stack<pair<int,int>> que;
    que.push(make_pair(0,0));
    F[0][0]=1;
    int h,w;
    
    
    int contf = 0;
    while(que.size()){
        
        h = que.top().first;
        w = que.top().second;
        que.pop();
        
        contf = F[h][w];
        
        if(h+1<H){
            if(S[h+1][w]=='#'){
                que.push(make_pair(h+1,w));
                F[h+1][w] = contf + 1;
            }
        }
        
        if(w+1<W){
            if(S[h][w+1]=='#'){
                que.push(make_pair(h,w+1));
                F[h][w+1] = contf + 1;
            }
        }
        
        
        if(F[h][w]==cont){
            
            cout << "Possible"<<endl;
            return 0;
        }
        
        
    }

    cout << "Impossible"<<endl;
    return 0;
    
}
