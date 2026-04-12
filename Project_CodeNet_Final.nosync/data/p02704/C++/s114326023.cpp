#include <bits/stdc++.h>
using namespace std;
int set_elem(bool r1, bool ror, bool c1, bool cor,int a,int b){
    int i=(!ror)*8+(r1)*4+(!cor)*2+(c1);
    vector<int> table={0,0,0,-1,0,1,a,1,0,b,0,1,-1,1,1,1};
    return table[i];
}
int main() {
    int N;
    cin>>N;
    vector<bool> row_or(N);
    vector<bool> column_or(N);
    vector<bitset<64>> U(N);
    vector<bitset<64>> V(N);
    vector<vector<bitset<64>>> mat(N,vector<bitset<64>>(N));
    for (int i = 0; i < N; i++){
        bool S;
        cin>>S;
        row_or[i]=S;
    }
    for (int i = 0; i < N; i++){
        bool T;
        cin>>T;
        column_or[i]=T;
    }
    for (int i = 0; i < N; i++){
        long long unsigned int u;
        cin>>u;
        U[i]=u;
    }
    for (int i = 0; i < N; i++){
        long long unsigned int v;
        cin>>v;
        V[i]=v;
    }
    for (int bit = 0; bit < 64; bit++){
        vector<vector<int>> row_count(2,vector<int>(2,0));
        vector<vector<int>> column_count(2,vector<int>(2,0));        
        for (int i = 0; i < N; i++){
            row_count[U[i][bit]][row_or[i]]++;
            column_count[V[i][bit]][column_or[i]]++;
        }
        int a,b;
        bool c=0;bool d;
        bool use_c=false;
        int row_0=row_count[0][0]+row_count[0][1];
        int column_0=column_count[0][0]+column_count[0][1];
        if(row_0==N&&column_0==0){
            if(row_count[0][0]==1||column_count[1][1]==1){
                cout<<-1<<endl;
                return 0;
            }
            use_c=true;
        }else if(row_0==0&&column_0==N){
            if(row_count[1][1]==1||column_count[0][0]==1){
                cout<<-1<<endl;
                return 0;
            }
            use_c=true;
        }
        if(row_0>0)a=1;
        else if(column_0<N)a=0;
        if(row_0<N)b=0;
        else if(column_0>0)b=1;
        for (int i = 0; i < N; i++){
        d=c;
            for (int j = 0; j < N; j++){
                if(use_c){
                    a=d;b=d;
                }
                int tmp=set_elem(U[i][bit],row_or[i], V[j][bit],column_or[j],a,b);
                if(tmp==-1){
                    cout<<-1<<endl; return 0;
                }
                mat[i][j][bit]=tmp;
                if((V[j][bit]==1&&column_or[j])||(V[j][bit]==0&&!column_or[j]))d=!d;

            }
            if((U[i][bit]==1&&row_or[i])||(U[i][bit]==0&&!row_or[i]))c=!c;
        }
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout<<mat[i][j].to_ullong()<<" ";
        }
        cout<<endl;
    }

}