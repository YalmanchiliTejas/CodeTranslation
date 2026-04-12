import math

n=int(input())
A=list(map(int,input().split()))
ans=1
h=A[0]
for i in range(1,n):
  if A[i]>=h:
    ans+=1
    h=A[i]
print(ans)