#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;(i)<(n);++i)





int ltrb[50][4];

const int Bsize=310;
long long B[Bsize][Bsize];

const long long NUTTA = -1;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


typedef pair<int,int> pii;

void nulu(int x,int y,long long c){
    // if(c==NUTTA) cerr <<"!!!!!!"<<endl;
    // cerr << "nuru"<<c<<endl;

    queue<pii> Q;

    Q.push(pii(x,y));


    while(!Q.empty()){
        pii p=Q.front();Q.pop();

        // if(B[p.second][p.first]==NUTTA)continue;
        B[p.second][p.first]=NUTTA;


        // cerr << p.first << " "<<p.second<<endl;
        //
        //
        // rep(xx,12){
        //     rep(yy,12){
        //         if(B[yy][xx]==NUTTA) cerr << ".";
        //         else cerr << B[yy][xx];
        //     }
        //     cerr <<endl;
        // }
        // cerr << endl;



        rep(i,4){
            int X=p.first +dx[i];
            int Y=p.second+dy[i];
            if(X<0 || Y<0 || X>=Bsize || Y>=Bsize)continue;
            if(B[Y][X] == c){
                B[Y][X]=NUTTA;
                Q.push(pii(X,Y));
            }
        }
    }


    // cerr << "nuru end"<<endl;

}


int main(){

    for(;;){
        int n;
        cin >> n;
        if(n==0)return 0;
        map<int,int> x_zahyous;
        map<int,int> y_zahyous;

        rep(i,n)rep(j,4){
            int in;
            cin >> in;
            ltrb[i][j] = in;
            if(j%2==0) x_zahyous[in]=-1;
            else       y_zahyous[in]=-1;
        }
        int i=1;
        for(auto& x:x_zahyous){
            x.second=i++;
        }

        i=1;
        for(auto& y:y_zahyous){
            y.second=i++;
        }
        // cerr << "  # "<< x_zahyous.size() <<"  "<<y_zahyous.size()<<endl;

        // continue;


        rep(i,n){
            rep(j,4){
                int in = ltrb[i][j];
                if(j%2==0) in = x_zahyous[in];
                else       in = y_zahyous[in];
                ltrb[i][j] = in;
                // cerr << in<<" ";
            }
            // cerr << endl;
        }

        rep(x,Bsize)rep(y,Bsize)B[x][y]=0LL;


        rep(i,n){
            long long  c=(1LL<<i);
            for(int x=ltrb[i][0]; x<ltrb[i][2]; x++){
                for(int y=ltrb[i][3]; y<ltrb[i][1]; y++){
                    // if(x>=Bsize||y>=Bsize) cerr << x <<","<<y<<endl;
                    B[x][y] |= c;
                }
            }
        }


        long long ret = 0LL;


        const int B_size=Bsize-1;

        // rep(x,20){
        //     rep(y,20){
        //         cerr << B[y][x]<<" ";
        //     }
        //     cerr<<endl;
        // }
        // cerr<<endl;

        rep(x,B_size){
            rep(y,B_size){
                if(B[y][x] != NUTTA){
                    nulu(x,y,B[y][x]);
                    ret++;


                    // rep(X,B_size){
                    //     rep(Y,B_size){
                    //         if(B[Y][X] == NUTTA)
                    //             cerr << "* ";
                    //         else
                    //             cerr << B[Y][X]<<" ";
                    //     }
                    //     cerr << endl;
                    // }
                    // cerr << endl;

                }
            }
        }


       cout << ret << endl;


    }

}