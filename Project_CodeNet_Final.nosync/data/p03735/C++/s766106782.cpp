#include <cstdio>
#include <cstdlib>

int N;
int x[200010], y[200010];
int x2[200010], y2[200010];
int n2;
int idx[200010];
long long res = 2000000000;
long long r1, r2;

int cmp(const void *aa, const void *bb)
{
	int i1 = *((int *)aa);
	int i2 = *((int *)bb);
	if(x2[i1] > x2[i2])
		return 1;
	else if(x2[i1] < x2[i2])
		return -1;
	return 0;
}
	

void solve()
{
	int i;
	int mni = 0;
	int mn = x[0];
	for(i=0; i<N; i++){
		if(mn > x[i]){
			mn = x[i];
			mni = i;
		}
	}
	int mxi = 0;
	int mx = y[0];
	for(i=0; i<N; i++){
		if(mx < y[i]){
			mx = y[i];
			mxi = i;
		}
	}
	n2 = 0;
	for(i=0; i<N; i++){
		if(i != mni && i != mxi){
			x2[n2] = x[i];
			y2[n2] = y[i];
			n2 ++;
		}
	}
	for(i=0; i<n2; i++)
		idx[i] = i;
	qsort(idx, n2, sizeof(int), cmp);
	int rmn1, rmx1;
	int rmn2, rmx2;
	rmn1 = x[mni];
	rmx2 = y[mxi];
	rmx1 = x[mxi];
	rmn2 = y[mni];
	if(rmx1 < x2[idx[n2-1]])
		r1 = x2[idx[n2-1]] - rmn1;
	else
		r1 = rmx1 - rmn1;
	int mniy=0, mny=-1;
	for(i=0; i<n2; i++){
		if(mny==-1 || mny > y2[idx[i]]){
			mniy = i;
			mny = y2[idx[i]];
		}
	}
	if(mny!=-1 && mny < rmn2)
		r2 = rmx2 - mny;
	else
		r2 = rmx2 - rmn2;
	res = r1 * r2;
	if(mni != mxi){
		rmn1 = x[mni];
		rmx1 = y[mxi];
		if(x[mxi] < y[mni]){
			rmn2 = x[mxi];
			rmx2 = y[mni];
		}
		else{
			rmx2 = x[mxi];
			rmn2 = y[mni];
		}
		mny = -1;
		int mxy = -1;
		for(i=0; i<n2; i++){
			int rmn2_2 = rmn2;
			if(rmn2_2 > x2[idx[i]])
				rmn2_2 = x2[idx[i]];
			int rmx2_2 = rmx2;
			if(rmx2_2 < x2[idx[n2-1]])
				rmx2_2 = x2[idx[n2-1]];
			if(mny != -1 && rmn2_2 > mny)
				rmn2_2 = mny;
			if(mxy != -1 && rmx2_2 < mxy)
				rmx2_2 = mxy;
			if(mny == -1 || mny > y2[idx[i]])
				mny = y2[idx[i]];
			if(mxy == -1 || mxy < y2[idx[i]])
				mxy = y2[idx[i]];
			r1 = rmx1 - rmn1;
			r2 = rmx2_2 - rmn2_2;
			if(r1 * r2 < res)
				res = r1 * r2;
		}
	}
	printf("%lld\n", res);
}

int main()
{
	int i;
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d %d", &x[i], &y[i]);
		if(x[i] > y[i]){
			int tmp = x[i];
			x[i] = y[i];
			y[i] = tmp;
		}
	}
	solve();
	return 0;
}