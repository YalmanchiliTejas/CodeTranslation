N = int(input())
A = list(map(int, input().split()))
sum_A = sum(A)
ans = 0
 
for i in range(N):
  sum_A = (sum_A - A[i])%(10**9 + 7)
  ans += A[i] * sum_A
  
print(ans%(10**9 + 7))