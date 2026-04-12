#include<iostream>
using namespace std;
int main( )
{
    char a[105][105];
    int l[105];
    int r[105];
    int n,m;
    cin>>n>>m;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++){
                cin>>a[i][j];
        }

    for(int i = 0;i < n;i++){
        int t = 0;
        for(int j = 0;j < m;j++){
            if(a[i][j] == '.')
                t++;
        }
        if(t == m) l[i] = 1;
    }

    for(int i = 0;i < m;i++){
        int t = 0;
        for(int j = 0;j < n;j++){
            if(a[j][i] == '.')
                t++;
        }
        if(t == n) r[i] = 1;
    }

    for (int i = 0; i < n; i++){
		int flag = 0;
		for (int j = 0; j < m; j++){
			if(l[i] || r[j]) continue;
			flag = 1;
			cout<<a[i][j];
		}
		if(flag) cout<<endl;
	}




   return 0;
}
