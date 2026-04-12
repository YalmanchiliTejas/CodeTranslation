N=int(input())
A=list(map(int,input().split()))
sumA=sum(A)
result=0
for i in range(N):
  sumA-=A[i]
  result+=A[i]*sumA
  result=result % (10**9+7)
  
print(result)