# C - Sum of product of pairs

n = int(input())
a = list(map(int, input().split()))
assert len(a) == n

modulus = 10 ** 9 + 7

s = sum(a)
sq = sum(x * x for x in a)
print(((s * s - sq) // 2) % modulus)
