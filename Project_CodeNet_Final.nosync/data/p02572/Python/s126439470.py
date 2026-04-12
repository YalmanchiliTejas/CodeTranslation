N = int(input())
As = list(map(int, input().split()))

_sum = 0
x = 0
for i in range(len(As) - 1):
    _sum += As[i+1] * (x + As[i])
    x += As[i]

print(_sum % (10**9 + 7))
