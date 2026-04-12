from itertools import accumulate

mod = 10 ** 9 + 7
input()
l = list(map(int, input().split()))
print(sum(a * b % mod for a, b in zip(list(accumulate(l))[:-1], l[1:])) % mod)