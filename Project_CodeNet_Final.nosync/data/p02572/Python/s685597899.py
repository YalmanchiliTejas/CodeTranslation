N = int(input())
b = 10**9+7
A = list((int(x) for x in input().split()))
sum = 0
for a in A:
  sum += a
ans = 0
for i in range(N-1):
  sum -= A[i]
  ans += A[i]*sum
print(ans % b)