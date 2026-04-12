#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i = (s); i < (e); i++)
#define FOE(i,s,e) for(int i = (s); i <= (e); i++)
#define FOD(i,s,e) for(int i = (s); i >= (e); i--)
#define ll long long
#define pb push_back

int n, m, x, y, z, k, w;
char s[300005];
int A[300005];
int T[1200005], label[1200005], close[1200005], open[1200005];

void bd(int x, int l, int r)
{
	if (l == r) 
	{ 
		T[x] = A[l - 1]; 
		if (s[l - 1] == '(') open[x] = l; else close[x] = 1;
		return; 
	}
	int mid = (l + r) / 2;
	bd(x * 2, l, mid);
	bd(x * 2 + 1, mid + 1, r);
	T[x] = min(T[x * 2], T[x * 2 + 1]);
	open[x] = max(open[x * 2], open[x * 2 + 1]);
	close[x] = close[x * 2] + close[x * 2 + 1];
}

void push(int x)
{
	T[x * 2] += label[x];
	T[x * 2 + 1] += label[x];
	label[x * 2] += label[x];
	label[x * 2 + 1] += label[x];
	label[x] = 0;
}

void update(int x, int l, int r, int tl, int tr, int val)
{
	if (tl > r || l > tr) return;
	if (tl <= l && r <= tr) 
	{ 
		T[x] += val; 
		label[x] += val; 
		return;
	}
	int mid = (l + r) / 2;
	push(x);
	update(x * 2, l, mid, tl, tr, val);
	update(x * 2 + 1, mid + 1, r, tl, tr, val); 
	T[x] = min(T[x * 2], T[x * 2 + 1]);
}

int query_min(int x, int l, int r, int tl, int tr)
{
	if (tl > r || l > tr) return n + 10;
	if (tl <= l && r <= tr) return T[x];
	int mid = (l + r) / 2;
	push(x);
	int a = query_min(x * 2, l, mid, tl, tr);
	int b = query_min(x * 2 + 1, mid + 1, r, tl, tr);
	return min(a, b);
}

void bracket(int x, int l, int r, int pos)
{
	if (l == r)
	{
		if (s[l - 1] == '(') s[l - 1] = ')'; else s[l - 1] = '(';
		close[x] = 1 - close[x];
		if (open[x] == 0) open[x] = l; else open[x] = 0;
		return;
	}
	int mid = (l + r) / 2;
	
	if (pos <= mid) bracket(x * 2, l, mid, pos);
	else bracket(x * 2 + 1, mid + 1, r, pos);
	
	open[x] = max(open[x * 2], open[x * 2 + 1]);
	close[x] = close[x * 2] + close[x * 2 + 1];
}

int q_first_close(int x, int l, int r)
{
	if (l == r) return l;
	int mid = (l + r) / 2;
	if (close[x * 2] > 0) return q_first_close(x * 2, l, mid);
	else return q_first_close(x * 2 + 1, mid + 1, r);
}

int q_last_one(int l, int r)
{
	int high, low, mid;
	high = r; low = l;
	
	while (high - low > 1)
	{
		mid = (high + low) / 2;
		int x = query_min(1, 1, n, mid, n);
		if (x >= 2) high = mid;
		else low = mid;
	}
	return high;
}

int q_first_open(int x, int l, int r, int tl, int tr)
{
	if (l == r) return open[x];
	int mid = (l + r) / 2;
	
	if (tr <= mid) return q_first_open(x * 2, l, mid, tl, tr);
	if (tl > mid) return q_first_open(x * 2 + 1, mid + 1, r, tl, tr);
	
	if (open[x * 2] >= tl) return q_first_open(x * 2, l, mid, tl, tr);
	else return q_first_open(x * 2 + 1, mid + 1, r, tl, tr);
}

int main ()
{
	while (~scanf("%d", &n))
	{
		scanf("%d", &m);
		memset(A, 0, sizeof(A));
		memset(T, 0, sizeof(T));
		memset(open, 0, sizeof(open));
		memset(close, 0, sizeof(close));
		memset(label, 0, sizeof(label));
		x = y = z = k = w = 0;
		
		scanf("%s", s);
		FOR(i, 0, n) if (s[i] == '(') A[i] = 1; else A[i] = -1;
		FOR(i, 1, n) A[i] += A[i - 1];
		
		bd(1, 1, n);
		
		while (m--)
		{
		//	p();
			
			scanf("%d", &x);
			
			if (s[x - 1] == '(') update(1, 1, n, x, n, -2);
			else update(1, 1, n, x, n, 2);
			bracket(1, 1, n, x);

		//	p();

			if (s[x - 1] == ')')
			{
				y = q_first_close(1, 1, n);
				update(1, 1, n, y, n, 2);
				bracket(1, 1, n, y);
			}
			else
			{
				y = q_last_one(1, x);
				y = q_first_open(1, 1, n, y, x);
				update(1, 1, n, y, n, -2);
				bracket(1, 1, n, y);
			}
			
			printf("%d\n", y);
		}
	}
	
	return 0;
}
		