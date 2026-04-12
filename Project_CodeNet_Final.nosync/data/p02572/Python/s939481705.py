n = int(input())
nums = list(map(int, input().split()))
total = sum(nums[1:])
ans = 0
for i in range(n-1):
    ans += nums[i] * total
    total -= nums[i+1]
print(ans%(10**9+7))