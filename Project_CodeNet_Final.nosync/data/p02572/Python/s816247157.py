(n,),a = [list(map(int, s.split())) for s in open(0)]
s2 = 0
mod = int(1e9+7)
inv_2 = pow(2, mod-2, mod)
for x in a:
    s2 += pow(x, 2, mod)
    s2 %= mod
a2 = pow(sum(a), 2, mod)
ans = ((a2 - s2) * inv_2) % mod
print(ans)