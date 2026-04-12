n = int(input())
nums = list(map(int,input().split()))

s1 = (sum(nums) - nums[0]) % (10**9 + 7)
sums = [s1]
for i in range(1,n):
  s = sums[i-1] - nums[i]
  s %= 10**9 + 7
  sums.append(s)

ans = 0
for i in range(n):
  temp = nums[i] * sums[i] % (10**9 + 7)
  ans += temp

print(ans%(10**9+7))