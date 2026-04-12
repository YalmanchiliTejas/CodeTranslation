N=int(input())
A=list(map(int,input().split()))
A2=0
for i in range(len(A)):
  A2+=A[i]**2
c=(sum(A))**2-A2
print(c//2%(10**9+7))

