#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  while(s!="#"){

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    int tab[10][10]={{}};
    int h=0,w=0;
    int i=0,j=0;
    for(int k=0;k<s.size();k++){
      if(s[k]=='/'){
	i++;
	if(!w)w=j;
	j=0;
      }else if(s[k]=='b'){
	tab[i][j++]=1;
      }else{
	int num=s[k]-'0';
	j+=num;
      }
    }
    h=i+1;

    tab[a][b]=0;
    tab[c][d]=1;

    int cou=0;
    for(int q=0;q<h;q++){
      if(q)cout << '/';
      cou=0;
      for(int p=0;p<w;p++){
	if(tab[q][p]==0){
	  cou++;
	}else{
	  if(cou)cout << cou;
	  cout << "b";
	  cou=0;
	}
      }
      if(cou)cout << cou;
    }
    cout << endl;
    cin >> s;
  }
  return 0;

}

