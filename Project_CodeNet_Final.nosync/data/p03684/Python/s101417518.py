A=range(input())
P=[map(int,raw_input().split())+[i]for i in A]
o=sorted
def r(x):
 if A[x]<x:A[x]=x=r(A[x])
 return x
def u((w,X)):x,y=o(map(r,X));A[y]=x;return(x<y)*w
def s(i):P.sort(key=lambda x:x[i]);return[(q[i]-p[i],(q[2],p[2]))for p,q in zip(P,P[1:])]
print sum(map(u,o(s(0)+s(1))))
