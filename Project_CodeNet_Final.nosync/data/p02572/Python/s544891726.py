N=int(input())
A=list(map(int,input().split()))
MOD=1000000007

D=[0]*N
s=0
for i in range(N):
    s += A[i]
    D[i] = s

s = 0
for i in range(1,N):
    a = A[i]*D[i-1]
    s = (s+a)%MOD
print(s)
