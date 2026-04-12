N=int(input())
A=list(map(int,input().split()))

c=0
for i in range(N):
    c=c+A[i]**2
    
print((sum(A)**2-c)//2%(10**9+7))