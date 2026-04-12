from functools import reduce

N = int(input())
A_list = list(map(int, input().split()))

sums = [A_list[0]]

for i in range(1, N):
    sums.append(sums[i-1] + A_list[i])

result = 0
for i in range(1, N):
    result += sums[i-1] * A_list[i]

result %= 10**9 + 7

print(result)
