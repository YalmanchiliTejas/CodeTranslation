#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map> 
#include <set>
#include <ctime> 
#include <queue> 

#define LL long long

using namespace std;

const int N = 200000+10;

int n;
int a[N];
struct node{
	int v;
	bool mk;
	node* next, *prev;	
	node() {mk = false;}
}*st, *ed, em;

int main()
{

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	st = ed = &em; em.mk = true;
	bool d = 1;
	for(int i = 1; i <= n; i++)
	{
		node *x = new node(); x->v = a[i];
		if(d)
		{
			x->next = NULL; x->prev = ed;
			ed->next = x;
			ed = x;
		}else
		{
			x->prev = NULL; x->next = st;
			st->prev = x;
			st = x;
		}
		d = !d;
	}
	if(n%2==0)
	{
		while(st) 
		{
			if(!st->mk)
				if(st->next)
					printf("%d ", st->v);
				else
					printf("%d\n", st->v);
			st = st->next;
		}
	}
	else
		while(ed)
		{
			if(!ed->mk)
				if(ed->prev)
					printf("%d ", ed->v);
				else
					printf("%d\n", ed->v);
			ed = ed->prev;
		}
}