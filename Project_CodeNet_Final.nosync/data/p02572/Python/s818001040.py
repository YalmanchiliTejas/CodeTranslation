n = int(input())
A = [*map(int, input().split())]
s = sum(A)
s *= s
for a in A: s -= a * a
s //= 2
print(s % (10**9 + 7))
