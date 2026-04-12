#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};

int main()
{
   char s[1010][1010];
   int b[1010][2];
   int h,w,ans=0;
   
   cin >> h >> w;
   for(int i=0;i<h;i++){
       scanf("%s",s[i]);
       b[i][0] = -1;
       b[i][1] = -1;
       for(int j=0;j<w;j++){
           if(s[i][j] == 'B'){
               b[i][1] = j;
               if(b[i][0] == -1) b[i][0] = j;
           }
       }
       ans = max(ans,b[i][1]-b[i][0]);
   }

    for(int i=0;i<h;i++){
        for(int j=i+1;j<h;j++){
            for(int k=0;k<4;k++){
                if(b[i][dx[k]] == -1 || b[j][dy[k]] == -1) continue;
                ans = max(ans,(j-i)+abs(b[i][dx[k]]-b[j][dy[k]]));
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

