#include <iostream>

using namespace std;

int main()
{
    string s[105],x;
    int h,w,c,k=0;
    scanf("%d%d",&h,&w);
    for(int i=0; i<h; i++)
    {
        cin>>x;
        if(x[0]=='.')
        {
            c=0;
            for(int j=0; j<w; j++)
            {
                if(x[j]=='.')
                {
                    c++;
                }
                else
                    break;
            }
            if(c==w){
                continue;
            }
        }
        s[k]=x;
        k++;
    }
    for(int i=0; i<k; i++)
    {
      for(int j=0;j<w;j++){
        if(s[i][j]=='.')
        {
            c=0;
            for(int a=0; a<k; a++)
            {
                if(s[a][j]=='.')
                {
                    c++;
                }
                else
                    break;
            }
            if(c==k){
                continue;
            }
        }
        printf("%c",s[i][j]);
    }
    if(i<k-1) puts("");
      }
    return 0;
}
