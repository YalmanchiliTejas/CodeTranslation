mod = 10**9 + 7
n = int(input())
nums = list(map(int, input().split(" ")))

ans = 0

ans = sum(nums) * sum(nums) - sum([num*num for num in nums])

print((ans // 2) % mod)