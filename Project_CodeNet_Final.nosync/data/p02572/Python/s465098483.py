n=int(input())

A=list(map(int,input().split()))

p=10**9+7

sumA=sum(A)

A2=0
for i in range(n):
  A2+=A[i]*A[i]

print(((sumA*sumA-A2)//2)%p)
