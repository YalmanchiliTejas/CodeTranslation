MOD=1000000007
N=input()
A = list(map(int,input().split()))
l=len(A)
s=0
B=sum(A)
for i in range(l):
    B-=A[i]
    s+=A[i]*B
print(s%MOD)