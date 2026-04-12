N = int(input())
A = map(int, input().split())
s = 0
ss = 0
MOD = 10 ** 9 + 7
for v in A:
    s += v
    ss += v * v
    s %= MOD
    ss %= MOD

out = s * s - ss
out %= MOD
if out % 2 == 1:
    out += MOD
out //= 2
print(out)
