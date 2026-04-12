N = int(input())
nums = list(map(int,input().split()))

total = 0
sums = []
tmp = 0

for i in range(1, N):
    tmp += nums[N-i]
    sums.append(tmp)

for i in range(N-1):
    a = nums[i]
    b = sums[N-(i+2)]
    total += a*sums[N-(i+2)]

print(total % (1000000000+7))
