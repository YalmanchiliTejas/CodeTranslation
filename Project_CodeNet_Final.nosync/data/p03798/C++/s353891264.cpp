#include <iostream>
#include <string>
#include <vector>
#include <string>

using namespace std;

void vec_cout(vector<int> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout<< vec[i];
    }
}

int determine(vector<int> &animal, int a, char c, int N){
    if (animal[a]==-1){
        c= (c=='o')?'x':'o';
    }
    if (c=='o'){
        if (animal[(a+1)%N]!=0 && animal[(N+a-1)%N] != animal[(a+1)%N]){
            //cout << a << ' ' << animal[(N+a-1)%N] << ' ' << animal[(a+1)%N] << endl;
            return -1;
        }
        animal[(a+1)%N]=animal[(N+a-1)%N];
    }else{
        if (animal[(a+1)%N]!=0 && animal[(N+a-1)%N] == animal[(a+1)%N]){
            //cout << a << ' ' << animal[(N+a-1)%N] << ' ' << animal[(a+1)%N] << endl;
            return -1;
        }
        animal[(a+1)%N]=-1*animal[(N+a-1)%N];
    }
    return 1;
}

int main(){
    int N;
    cin >> N;

    string line;
    cin >> line;

    int flag=0;
    vector<int> ans;

    vector<vector<int>> initial(4,vector<int>(2,0));
    initial={{1,1},{-1,-1},{1,-1},{-1,1}};

    for(int i=0; i<4; i++){
        vector<int> animal(N,0);
        animal[0]=initial[i][1];
        animal[N-1]=initial[i][0];
        flag=1;
        for(int j=0; j<N; j++){
            if (determine(animal,j,line[j],N)==-1){
                flag=0;
                break;
            }
        }
        if (flag==1){
            ans=animal;
            break;
        }
        //vec_cout(animal);
        //cout<<endl;
    }
    if (flag==0){
        cout << -1 << endl;
    }else{
        for(int i=0; i<N; i++){
            if(ans[i]==1){
                cout << 'S';
            }else{
                cout << 'W';
            }
        }
        cout<<endl;
    }
}