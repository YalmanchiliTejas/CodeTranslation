N = int(input())
A = list(map(int,input().split()))
 
ans = 0
sum = 0
for i in range(1,N):
  
  sum = sum + A[i-1]
  ans = (ans + sum*A[i])%(10**9+7)
  
print(ans)