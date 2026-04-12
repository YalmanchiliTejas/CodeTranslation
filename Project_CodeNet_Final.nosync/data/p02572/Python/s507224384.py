N = int(input())
A = list(map(int, input().split()))

base = int(1e9+7)
tot = 0

s = 0
for a in A:
    tot += s*a
    s += a
    tot %= base

print(tot)
