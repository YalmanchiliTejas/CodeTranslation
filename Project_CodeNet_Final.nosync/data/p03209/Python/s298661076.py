def rec(N,X):
    if N==0:
        return 1
    if X==0:
        return 0
    if 1<=X and X<=a[N-1]:
        return rec(N-1,X-1)
    if X==a[N-1]+1:
        return p[N-1]+1
    if a[N-1]+1<X:
        return rec(N-1,X-a[N-1]-2)+p[N-1]+1

N,X=map(int,input().split())
A,P=1,1
a,p=[],[]
for i in range(51):
    a.append(A);p.append(P)
    A=A*2+3;P=P*2+1
print(rec(N,X-1))