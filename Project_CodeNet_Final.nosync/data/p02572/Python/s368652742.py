n = int(input())

nums = list(map(int, input().split()))

ans = 0
s = sum(nums)
for i in range(n):
    s -= nums[i]
    ans += nums[i] * s

print(ans % (10**9+7))