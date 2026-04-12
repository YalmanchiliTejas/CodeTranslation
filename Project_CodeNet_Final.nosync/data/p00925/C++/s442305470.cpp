#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)

typedef long long ll;

const int N = 17;
int n;
int dgt[N], oprt[N];
char input[N+5];

int main() {
	int i, j, k;
	int tgt;

	memset(input, 0, sizeof(input));
	gets(input);
	i = j = k = 0;
	char c = input[0];
	while (c=='+' || c=='*' || ('0'<=c && c<='9')) {
		c = input[k++];
		if (c=='+' || c=='*')
			oprt[j++] = c;
		else if ('0'<=c && c<='9')
			dgt[i++] = c - '0';
	}
	n = i;

/*
printf("dgt:");
for (i=0; i<n; i++)
	printf("%d ", dgt[i]);
puts("");

printf("oprt:");
for (i=0; i<n-1; i++)
	printf("%c ", oprt[i]);
puts("");
*/

	scanf("%d ", &tgt);
//printf("tgt = %d\n", tgt);

	vector<int> mlt;
	mlt.push_back(dgt[0]);
	i = j = 0;
	while (j<n-1) {
		if (oprt[j]=='*')	{
			mlt[i] *= dgt[j+1];
		} else {
			mlt.push_back(dgt[j+1]);
			i++;
		}
		j++;	
	}
	int mltRes = mlt[0];
	for (i=1; i<mlt.size(); i++)
		mltRes += mlt[i];
//printf("mltRes = %d\n", mltRes);

	int addRes = dgt[0];	
	for (i=0; i<n-1; i++)
		if (oprt[i]=='*')
			addRes *= dgt[i+1];
		else
			addRes += dgt[i+1];
//printf("addRes = %d\n", addRes);

	char res = 'I';
	if (mltRes==tgt && addRes==tgt)
		res = 'U';
	else if (mltRes==tgt)
		res = 'M';
	else if (addRes==tgt)
		res = 'L';

	printf("%c\n", res);

	return 0;
}