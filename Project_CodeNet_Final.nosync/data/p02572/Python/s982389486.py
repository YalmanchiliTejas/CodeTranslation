import math

N = int(input())
An = [int(i) for i in input().split()]


mod = int(math.pow(10, 9) + 7)

sum_an = sum(An)
sum_result = 0

for i in range(N - 1):
    Ai = An[i]
    sum_an -= Ai
    sum_result += (Ai * sum_an) % mod


print(sum_result % mod)
