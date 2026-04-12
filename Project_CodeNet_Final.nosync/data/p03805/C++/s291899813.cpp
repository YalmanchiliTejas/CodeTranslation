#include<iostream>
using namespace std;

unsigned long long ans = 0;
int n, m;
bool connect[8][8];

void search(int position, bool done[]){
    done[position] = true;
    //cout << "position:" << position << ",";
    //for(int i=0;i<n;i++)cout << done[i] << ",";
    //cout << endl;
    int check = 0;
    for(int i=0;i<n;i++){
        if(done[i])check++;
    }
    if(check==n){
        ans++;
    }

    for(int i=0;i<n;i++){
        if(connect[position][i] && (!done[i]))search(i, done);
    }
    done[position] = false;
}

int main(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)connect[i][j] = false;
    }

    int a[m], b[m];
    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
        connect[a[i]-1][b[i]-1] = true;
        connect[b[i]-1][a[i]-1] = true;
    }

    bool done[n];
    for(int i=0;i<n;i++)done[i] = false;
    done[0] = true;
    int position = 0;
    search(position, done);

    cout << ans << endl;
}
