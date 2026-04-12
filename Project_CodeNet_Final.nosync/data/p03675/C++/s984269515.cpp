#include <iostream>
using namespace std;

struct VV {
	VV *bef=NULL;
	VV *nex=NULL;
	int v;
}*l,*r;
void insertl(int val) {
	VV *tmp = new VV();
	tmp->v = val;
	l->bef = tmp;
	tmp->nex = l;
	l=tmp;
}
void insertr(int val) {
	VV *tmp = new VV();
	tmp->v = val;
	r->nex = tmp;
	tmp->bef = r;
	r=tmp;
}
int main() {
	int n;
	cin>>n; n--;
	int tmp; cin>>tmp;
	r = l = new VV();
	r->v = tmp; r->bef=r->nex=NULL;
	bool direction = true;
	while (n--) {
		int tt; cin>>tt;
		if (direction)
			insertr(tt);
		else
			insertl(tt);
		direction = !direction;
	}
	if (direction)
		for (VV *t=l;t;t=t->nex)
			cout<<t->v<<" ";
	else
		for (VV *t=r;t;t=t->bef)
			cout<<t->v<<" ";
	cout<<endl;
	return 0;
}
