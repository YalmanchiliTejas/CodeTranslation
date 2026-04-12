n = int(input())
a = list(map(int, input().split()))

mod = 10 ** 9 + 7
N = 1000

#逆元テーブル
inv_t = [0]+[1]
for i in range(2, N):
  inv_t += [inv_t[mod % i] * (mod - int(mod / i)) % mod]

#階乗計算
kai = [1, 1]
rev_kai = [1, inv_t[1]]
for i in range(2, N):
	kai.append(kai[-1] * i % mod)
	rev_kai.append(rev_kai[-1] * inv_t[i] % mod)

# コンビネーション計算
def cmb(n, r):
	return kai[n] * rev_kai[r] * rev_kai[n-r] % mod

tmp1 = 0
tmp2 = 0
mod = 10 ** 9 + 7
for ai in a:
    tmp1 += (ai ** 2) % mod
    tmp1 %= mod
    tmp2 += ai
    tmp2 %= mod

print((tmp2 ** 2 - tmp1) * inv_t[2] % mod)
