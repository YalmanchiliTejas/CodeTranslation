import itertools
N = int(input())
A =  list(map(int, input().split()))
sa = sum(A)
r = 0
xx = sa
m = 10**9+7
for x in A:
    xx -= x
    r += x*xx
    r = r % m
print(r)