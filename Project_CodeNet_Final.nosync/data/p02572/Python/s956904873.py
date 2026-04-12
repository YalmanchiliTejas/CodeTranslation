N = int(input())
nums = list(map(int, input().split()))
print((sum(nums)**2 - sum([i**2 for i in nums])) // 2 % (10**9 + 7))

