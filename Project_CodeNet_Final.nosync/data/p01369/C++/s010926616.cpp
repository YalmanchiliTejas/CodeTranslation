
#include<bits/stdc++.h>

using namespace std;

int main(){
	string str;
	while(cin>>str,str!="#"){
		bool flag=true;
		int co=0;
		switch(str[0]){
				case 'a':
				case 'q':
				case 'z':
				case 'x':
				case 's':
				case 'w':
				case 'e':
				case 'd':
				case 'c':
				case 'v':
				case 'f':
				case 'r':
				case 't':
				case 'g':
				case 'b':
					flag=true;
					break;				
				case 'n':
				case 'h':
				case 'y':
				case 'u':
				case 'j':
				case 'm':
				case 'k':
				case 'i':
				case 'o':
				case 'l':
				case 'p':
					flag=false;
					break;
			}
		for(int i=1;i<str.size();i++){
			switch(str[i]){
				case 'a':
				case 'q':
				case 'z':
				case 'x':
				case 's':
				case 'w':
				case 'e':
				case 'd':
				case 'c':
				case 'v':
				case 'f':
				case 'r':
				case 't':
				case 'g':
				case 'b':
					if(flag==false){
						co++;
					}
					flag=true;
					break;					
				case 'n':
				case 'h':
				case 'y':
				case 'u':				
				case 'j':
				case 'm':
				case 'k':
				case 'i':
				case 'o':
				case 'l':
				case 'p':
					if(flag==true){
						co++;
					}
					
					flag=false;
					break;
			}
		}
		cout<<co<<endl;
	}
}
	