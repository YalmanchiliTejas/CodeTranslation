N = int(input())
A = list(map(int, input().split()))

left = A[0]
left %= (10**9)+7
right = sum(A) - A[0]
right %= (10**9)+7
ans = 0
for i in range(1, N):
  tmp = left * right
  tmp %= (10**9)+7
  ans += tmp
  ans %= (10**9)+7
  left = A[i]
  right -= A[i]
print(ans)