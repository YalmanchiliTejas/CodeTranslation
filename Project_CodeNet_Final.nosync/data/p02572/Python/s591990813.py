n=int(input())
A=list(map(int,input().split()))
sumA=sum(A)
x=0
for i in range(n-1):
  sumA-=A[i]
  x+=A[i]*sumA
print(x%(10**9+7))