n = int(input())
a = list(map(int, input().split()))

mod = 10**9+7
nums = [0]*n
nums[0] = a[0]
for i in range(1,n): nums[i] = a[i] + nums[i-1]

ans = 0
for i in range(n-1):
  ans += a[i] * (nums[n-1]-nums[i])
  ans %= mod
print(ans)