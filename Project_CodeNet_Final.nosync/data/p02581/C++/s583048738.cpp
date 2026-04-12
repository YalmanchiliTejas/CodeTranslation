#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int A[6005];
int dp[2005][2005];
int buf[2005][2005];

int max_row[2005],max_col[2005],max_val;

int cx[]={0,1,2},cy[]={1,2,0},cz[]={2,0,1};

void assign(int k,int q){
    dp[k][q]=buf[k][q];
    max_row[k]=max(max_row[k],dp[k][q]);
    max_col[q]=max(max_col[q],dp[k][q]);
    max_val=max(max_val,dp[k][q]);
}

int main(){
    scanf("%d",&N);
    for(int i=1;i<=3*N;i++) scanf("%d",A+i);

    dp[A[1]][A[2]]=2;
    max_val=2;
    max_row[A[1]]=2;
    max_row[A[2]]=2;

    int offset=0;
    for(int i=0;i<N;i++){
        auto *cur=A+(i+1)*3;
        
        if (cur[0]==cur[1]&&cur[1]==cur[2]){
            offset++;
            continue;
        }

        for(int i=0;i<3;i++){
            int selx=cx[i],sely=cy[i],unsel=cz[i];
            if (cur[selx]!=cur[sely]) continue;
            int p=cur[selx],q=cur[unsel];
            for(int k=1;k<=N;k++)
                buf[k][q]=max(buf[k][q],max(dp[p][k]+1,dp[k][p]+1));
        }

        for(int i=0;i<3;i++){
            int sel=cx[i],unselx=cy[i],unsely=cz[i];
            int p=cur[sel],q=cur[unselx],l=cur[unsely];
            buf[q][l]=max(dp[p][p]+1,buf[q][l]);
        }

        for(int i=0;i<3;i++){
            int sel=cx[i],unselx=cy[i],unsely=cz[i];
            int p=cur[sel],q=cur[unselx],l=cur[unsely];
            buf[q][l]=max(max_val,buf[q][l]);
        }

        for(int i=0;i<3;i++){
            int p=cur[i];
            for(int k=1;k<=N;k++)
                buf[k][p]=max(buf[k][p],max_row[k]),buf[k][p]=max(buf[k][p],max_col[k]);
        }

        //

        for(int i=0;i<3;i++){
            int selx=cx[i],sely=cy[i],unsel=cz[i];
            if (cur[selx]!=cur[sely]) continue;
            int p=cur[selx],q=cur[unsel];
            for(int k=1;k<=N;k++){
                assign(k,q);
            }
        }

        for(int i=0;i<3;i++){
            int sel=cx[i],unselx=cy[i],unsely=cz[i];
            int p=cur[sel],q=cur[unselx],l=cur[unsely];
            assign(q,l);
        }

        for(int i=0;i<3;i++){
            int sel=cx[i],unselx=cy[i],unsely=cz[i];
            int p=cur[sel],q=cur[unselx],l=cur[unsely];
            assign(q,l);
        }

        for(int i=0;i<3;i++){
            int p=cur[i];
            for(int k=1;k<=N;k++)
                assign(k,p);
        }

    }

    printf("%d\n",max_val+offset-2);





    return 0;
}