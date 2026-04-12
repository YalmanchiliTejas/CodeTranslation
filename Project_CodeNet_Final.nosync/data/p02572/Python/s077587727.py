N=int(input())
A=list(map(int,input().split()))
s=sum(A)
ss=s
z=0
for i in range(0,N-1):
    ss-=A[i]
    z+=A[i]*ss

print(z%1000000007)
