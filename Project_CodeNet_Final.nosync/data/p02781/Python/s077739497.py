def combination(n, k, mod=10**9+7):
    if n < k:
        return 0
    if n-k < k:
        k = n-k
    comb = 1
    for x in range(n-k+1, n+1):
        comb = (comb * x) % mod
    d = 1
    for x in range(1, k+1):
        d = (d * x) % mod
    comb *= pow(d, mod-2, mod)
    return comb % mod

N = int(input())
K = int(input())

x = [0] * 101
i = 0
NN = N
while NN > 0:
    x[i] = NN % 10
    NN = NN // 10
    i += 1

ans = 0
sum_non0 = 0
rK = K
for j in reversed(range(i)):
    if x[j] == 0:
        continue
    # 0 ~ 10^j
    _ans = combination(j, rK) * (9 ** rK)
    #print(j, _ans)
    if rK != 1:
        _ans += (x[j] - 1) * combination(j, rK-1) * (9 ** (rK - 1))
        #print(j, _ans)
    else:
        _ans += x[j]
        #print(j, _ans)

    ans += _ans
    rK -= 1
    if rK == 0:
        break

print(ans)