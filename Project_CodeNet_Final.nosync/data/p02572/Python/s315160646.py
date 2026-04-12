from itertools import accumulate

MOD = 10 ** 9 + 7

n = int(input())

a = list(map(int, input().split()))

suffix_sum = list(accumulate(a[::-1]))[::-1]

req_arr = [x -  y for x, y in zip(suffix_sum, a)]

result = sum([(x * y) % MOD for x, y in zip(req_arr, a)])

print(result % MOD)
