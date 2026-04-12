#include <iostream>
using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    char table[H][W];
    bool H_output[H]={false}, W_output[W]={false};
    int  i, j;
    
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            cin >> table[i][j];
            if(table[i][j]=='#')
            {
                H_output[i] = true;
                W_output[j] = true;
            }
        }
    }
  
    for(i=0;i<H;i++){
        for(j=0;j<W;j++){
            
            if(H_output[i] && W_output[j])
            {
                cout << table[i][j];
            }
        }
       if(H_output[i])
        {
            cout << endl;
        }
    }
    return 0;
}