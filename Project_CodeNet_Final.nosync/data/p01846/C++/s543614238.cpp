#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while( cin >> s ){
		if( s[0] == '#' ) break;
		int w=0;
		for(int i = 0 ; s[i] != '/' &&  i < s.size() ; i++ ){
			if(s[i] == 'b') w++;
			else{
				w += s[i] - '0';
			}
		}
		
		int h=1;
		
		for( int i = 0 ; i < s.size() ; i++ ){
			if( s[i] == '/' ) h++;
		}

		//cout << h << " " << w << endl;
		
		vector<vector<bool>> f(h,vector<bool> (w)); 
		
		int i = 0 , j=0;
		for( int k = 0 ; k < s.size() ; k++ ){
			//cout << "k:" << k << " i:" << i << " j:" << j << " s:" << s[k] <<  endl;
			if(s[k] == 'b'){
				f[i][j]=1;
				j++;
			}
			else if( s[k] == '/' ){
				i++;
				j=0;
			}
			else{
				j += s[k]-'0';
			}
		}
	
		/*
		for(int i = 0 ; i < h ; i++ ){
			for(int j = 0 ; j < w ; j++ ){
				cout << f[i][j];
			}
			cout << endl;
		}
		*/
		

		int a,b,c,d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		f[a][b]=0; f[c][d]=1;
		
		
		/*
		for(int i = 0 ; i < h ; i++ ){
			for(int j = 0 ; j < w ; j++ ){
				cout << f[i][j];
			}
			cout << endl;
		}
		*/


		int cnt = 0;
		for(int i = 0 ; i < h ; i++ ){
			for(int j = 0; j < w ; j++ ){
				if( !f[i][j] ) cnt++;
				else{
					if( cnt ){
						cout << cnt;
						cnt = 0;
					}
					
					cout << "b";
				}
			}
			
			if( cnt ){
				cout << cnt;
				cnt = 0;
			}

			if( i < h-1 )
				cout << '/';
		}
		cout << endl;

	}
}
