mod = 1000000007
N = int(input())
A = list(map(int, input().split()))

X = 0
Y = 0
for a in A:
    X += a
    Y += a * a
X = (X * X) % mod
Y = Y % mod
Z = (X - Y + mod) % mod
ans = 0
if Z % 2 == 0:
    ans = Z / 2
else:
    ans = (Z + mod) / 2
print(int(ans))
