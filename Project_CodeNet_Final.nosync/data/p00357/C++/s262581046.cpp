#include <iostream>
using namespace std;

const int lim = 300000;
bool jud[lim];
int dis[lim];

int main()
{
    for(int i=0;i<lim;i++){
        jud[i] = false;     
    }
    
    int n;
    cin >> n;	
    for(int i=0;i<n;i++){
        int d;
        cin >> d;
        dis[i] = d;
    }

    int count = 0;
    jud[0] = true;            
    bool ans = false;
    while(jud[count]&&count<n){
        if(count==n-1){
            ans = true;
            break;
        }
        int jump;
        if(count+dis[count]/10>=lim){
            jump = lim-1;
        }else{
            jump = count+dis[count]/10;
        }
        for(int i=jump;!jud[i];i--){
            jud[i] = true;
        }
        count++;
    }
    
    if(ans){
        for(int i=0;i<lim;i++){
            jud[i] = false;     
        }
        jud[n-1] = true;            
        ans = false;
        while(jud[count]&&count<=n){
            if(count==0){
                ans = true;
                break;
            }
            /*for(int i=1;i<=dis[count]/10&&count-i>=0;i++){
                jud[count-i] = true;
            }
            count--;*/
            int jump;
            if(count-dis[count]/10<0){
                jump = 0;
            }else{
                jump = count-dis[count]/10;
            }
            for(int i=jump;!jud[i];i++){
                jud[i] = true;
            }
            count--;
        } 
    }

    if(ans){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }

    return 0;
}
