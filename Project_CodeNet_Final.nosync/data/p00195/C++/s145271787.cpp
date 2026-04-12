#include <iostream>
using namespace std;
int main(void){
    int s1[5], s2[5]; //午前と午後の販売個数
    
    while(true){
        for(int i = 0; i < 5; i++){
            cin >> s1[i] >> s2[i];
            if(s1[0] == 0 && s2[0] == 0) return 0;
        }

        int sum[5]; //１日の販売個数
        int max = 0; //１日の販売個数の最大値
        char n[5] = {'A', 'B', 'C', 'D', 'E'}; //店名
        int p; //１日の販売個数が最大のお店

        for(int i = 0; i < 5; i++){
            sum[i] = s1[i] + s2[i];
            if(sum[i] > max){
                max = sum[i];
                p = i;
            }
        }
        cout << n[p] << " " << max << endl;
    }
        /*if(max_name == 1) cout << "A" << " " << max << endl;
        if(max_name == 2) cout << "B" << " " << max << endl;
        if(max_name == 3) cout << "C" << " " << max << endl;
        if(max_name == 4) cout << "D" << " " << max << endl;
        if(max_name == 5) cout << "E" << " " << max << endl;*/
}  

