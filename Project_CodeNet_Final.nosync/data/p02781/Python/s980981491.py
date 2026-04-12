import sys
def input():
    return sys.stdin.readline()[:-1]
# import itertools
N = int(input())
K = int(input())

L = list(str(N))
leng = len(L)
st = int(L[0])
cnt = 0

#N(3003)と左桁数(0)をもらってOKな桁数(3)とその数値を返す
def keta(n,l):
    for i in range(l,leng):
        d = n[i]
        if d=='0':
            continue
        else:
            return (i,int(d))
    return -1,-1

if K==1:
    cnt += st
    cnt += 9*(leng-1)
elif K==2:
    i,d = keta(L,1)
    if not i==-1:
        cnt += d + 9*(leng-i-1)

    cnt += (st-1)*9*(leng-1) + 9*9*(leng-1)*(leng-2)//2
else:
    i_1,d_1 = keta(L,1)
    i_2,d_2 = keta(L,i_1+1)
    if not i_1==-1:
        a = (leng-i_1-1)
        cnt += (d_1-1)*9*a
        cnt += 9*9*(a*(a-1)//2)
    if not i_2==-1:
        cnt += d_2 + 9*(leng-i_2-1)
    cnt += (st-1)*9*9*(leng-1)*(leng-2)//2 + (9**3)*(leng-1)*(leng-2)*(leng-3)//6
print(cnt)