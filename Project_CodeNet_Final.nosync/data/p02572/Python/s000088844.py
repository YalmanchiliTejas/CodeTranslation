from itertools import accumulate

n = int(input())
a = list(map(int, input().split()))
b = list(accumulate(a))
sum = 0

for i in range(len(a)):
    sum += a[i]*(b[-1] - b[i])
    sum %= 10**9 + 7

print(sum)
