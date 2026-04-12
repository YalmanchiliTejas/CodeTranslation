N = int(input())
A = list(map(int, input().split()))
 
answer = 0
a_sum = sum(A)
mod = 10**9+7
 
for i in range(N-1):
  a_sum -= A[i]
  answer += a_sum * A[i]
print(str(answer % mod))