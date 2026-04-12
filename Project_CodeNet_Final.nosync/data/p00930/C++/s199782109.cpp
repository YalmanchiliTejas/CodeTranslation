#include <cstdio>
#include <algorithm>
#define lc(x) ((x)*2)
#define rc(x) ((x)*2+1)
using std::min;

const int INF = 10000000;
const int MAXN = 300000+10;

int N, Q;
char S[MAXN];
//Tree
int SIZE=1, Root=1;
int tag[8*MAXN];
int Min[8*MAXN]; //????¶´???
bool HaveR[8*MAXN]; //????????¬???

int change(int no, int l, int r, int pos){
    if(l==r){
        HaveR[no] = 1-HaveR[no];
        if(HaveR[no]) return 1;
        else return 2;
    }
    int mid = (l+r)/2;
    int tmp;
    if(pos <= mid) tmp = change(lc(no), l, mid, pos);
    if(mid < pos)  tmp = change(rc(no), mid+1, r, pos);
    HaveR[no] = HaveR[lc(no)] + HaveR[rc(no)];
    return tmp;
}

void maintain(int no){
    if(tag[no] != 0){
        Min[lc(no)] += tag[no];
        Min[rc(no)] += tag[no];
        tag[lc(no)] += tag[no];
        tag[rc(no)] += tag[no];
        tag[no] = 0;
    }
    if(no<SIZE) Min[no] = min(Min[lc(no)], Min[rc(no)]);
    return;
}

void puttag(int no, int l, int r, int ql, int qr, int k){
    if(r < ql || qr < l) return;
    if(ql<=l && r<=qr){
        Min[no] += k;
        tag[no] += k;
        return;
    }
    maintain(no);
    int mid = (l+r)/2;
    puttag(lc(no), l, mid, ql, qr, k);
    puttag(rc(no), mid+1, r, ql, qr, k);
    maintain(no);
    return;
}

int find_r(int no, int l, int r){
    if(l==r) return l;
    int mid = (l+r)/2;
    if(HaveR[lc(no)])
        return find_r(lc(no), l, mid);
    return find_r(rc(no), mid+1, r);
}
int find_min(int no, int l, int r){
    if(l==r) return l;
    maintain(no);
    int mid = (l+r)/2;
    if(Min[rc(no)] < 0)
        return find_min(rc(no), mid+1, r);
    return find_min(lc(no), l, mid);
}

void build_tree(){
    SIZE=1;
    while(SIZE < N) SIZE*=2; //1-Root
    int sum=0;
    for(int i=N ; i<=SIZE; i++){
        Min[SIZE+i] = INF;
    }
    for(int i=N-1 ; i>=0 ; i--){ //size,size+1..?????????
        if(S[i] == ')'){
            HaveR[SIZE+i] = true;
            sum++;
        }
        else{
            HaveR[SIZE+i] = false;
            sum--;
        }
        Min[SIZE+i] = sum;
    }
    for(int i=SIZE-1;i>=1;i--){
        HaveR[i] = HaveR[lc(i)] + HaveR[rc(i)];
        Min[i] = min( Min[lc(i)], Min[rc(i)] );
    }
}

int main(){
    scanf("%d %d", &N, &Q);
    scanf("%s", S);
    build_tree();
    while(Q--){
        int pos;
        scanf("%d", &pos);
        int x = change(Root, 1, SIZE, pos);
        if(x==1){ // '(' --> ')'
            puttag(Root, 1, SIZE, 1, pos, 2);
            pos = find_r(Root, 1, SIZE);
            change(Root, 1, SIZE, pos);
            puttag(Root, 1, SIZE, 1, pos, -2);
        }else{ // ')' --> '('
            puttag(Root, 1, SIZE, 1, pos, -2);
            pos = find_min(Root, 1, SIZE);
            change(Root, 1, SIZE, pos);
            puttag(Root, 1, SIZE, 1, pos, 2);
        }
        printf("%d\n", pos);
    }
    return 0;
}