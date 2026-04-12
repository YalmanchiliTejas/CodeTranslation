MOD = 1000000007
n = int(input())
nums = list(map(int, input().split()))
x = sum(nums)
y = sum([(nums[i]**2) for i in range(n)])
print(((x**2 - y)//2)% MOD)