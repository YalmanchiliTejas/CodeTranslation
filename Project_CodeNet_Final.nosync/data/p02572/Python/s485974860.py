MOD = 10**9 + 7
N = input()
A = [int(hoge) for hoge in input().split()]
S = 0
Scube = 0
for a in A:
    S += a
    Scube += a**2
    S %= MOD
    Scube %= MOD
Double = S**2 - Scube
Double %= MOD
if Double%2:
    Double += MOD
    Double //= 2
else:
    Double //= 2
print(Double)