#include <stdio.h>
int main() {
    int RideBack[29][29],i,j,k,N;while (1) {
        for (i=0;i<29;i++) for (j=0;j<29;RideBack[i][j++]=0);scanf("%d",&N);if (!N) return 0;k=N*N,i=N-1,j=(N-1)*3-i;while (k>0) {RideBack[i][j]=k--;i--,j--;if (k%N==0) i+=1+N,j=(N-1)*3-i;}
        for (i=1;i<29;i++) for (j=N/2-1;j>=0;j--) if (RideBack[i][j]) RideBack[i][j+N]=RideBack[i][j],RideBack[j+N][i]=RideBack[j][i];
        for (i=1;i<29;i++) for (j=N/2+N;j<N*2-1;j++) if (RideBack[i][j]) RideBack[i][j-N]=RideBack[i][j],RideBack[j-N][i]=RideBack[j][i];
        for (j=N/2;j<N/2+N;j++,puts("")) for (i=N/2;i<N/2+N;i++) printf("%4d",RideBack[i][j]);
    }
}