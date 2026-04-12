#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<vector>
#include<deque>

#define MN 100009

using namespace std;

typedef struct TOWN{
  int x, y, i;
}Town;

typedef struct COST{
  int p[2];
  int c;
}Cost;

int N;
long x[MN], y[MN];
vector<Cost> cost;
vector<Town> town;
vector<int> number[MN];
int iv[MN];
long total = 0;

bool comp(const Cost &l, const Cost &r){
  return l.c < r.c;
}

bool compX(const Town &l, const Town &r){
  return l.x==r.x ? l.i < r.i : l.x < r.x;
}

bool compY(const Town &l, const Town &r){
  return l.y==r.y ? l.i < r.i : l.y < r.y;
}

void printTown(){
  cout << "print town" << endl;
  for( int i = 0; i < N; i++ ){
	cout << town[i].x << "," << town[i].y << ":" << town[i].i << endl;
  }
}

void print(){
  int N2 = (N-1)*2;
  cout << "print cost" << endl;
  for( int i = 0; i < N2; i++ ){
	cout << cost[i].p[0] << "," << cost[i].p[1] << ":" << cost[i].c << endl;
  }
}

int main(){
  cin >> N;
  int N2 = (N-1)*2;
  cost.resize(N2);
  town.resize(N);
  for( int i = 0; i < N; i++ ){
	cin >> town[i].x >> town[i].y;
	town[i].i = i;
	iv[i] = i;
	number[i].push_back(i);
  }
  //printTown();
  sort(town.begin(), town.end(), compX);
  for( int i = 0; i < N-1; i++ ){
	cost[i].p[0] = town[i].i;
	cost[i].p[1] = town[i+1].i;
	cost[i].c = town[i+1].x-town[i].x;
  }
  //printTown();
  sort(town.begin(), town.end(), compY);
  //printTown();
  for( int i = 0; i < N-1; i++ ){
	cost[i+N-1].p[0] = town[i].i;
	cost[i+N-1].p[1] = town[i+1].i;
	cost[i+N-1].c = town[i+1].y-town[i].y;
  }
  //print();
  sort(cost.begin(), cost.end(), comp);
  //print();
  int k = 1;
  int p0, p1, vn, vn2;
  for( int i = 0; i < N2; i++ ){
	p0 = cost[i].p[0];
	p1 = cost[i].p[1];
	//cout << p0 << "," << p1 << ":" << cost[i].c << endl;
	vn = iv[p0]>iv[p1] ? iv[p0] : iv[p1];
	vn2 = iv[p0]<=iv[p1] ? iv[p0] : iv[p1];
	if( iv[p0] == iv[p1] ){ continue; }
	int l = number[vn2].size();
	for( int j = 0; j < l; j++ ){
	  int tmp = number[vn2].at(j);
	  iv[tmp] = vn;
	  number[vn].push_back(tmp);
	}
	number[vn2].clear();
	number[vn2].shrink_to_fit();
	k++;
	total += cost[i].c;
	if( k >= N ){ break; }
  }
  cout << total << endl;
  return 0;
}