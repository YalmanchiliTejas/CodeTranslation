n, x, m = map(int, input().split())
mn = min(n, m)
P = [] # value of pre & cycle
sum_p = 0 # sum of pre + cycle
X = [False] * m # for cycle check
for _ in range(mn):
    if X[x]:
        pre_len = P.index(x)
        cyc_len = len(P) - pre_len
        nxt_len = (n - pre_len) % cyc_len
        cyc = sum(P[pre_len:]) * ((n - pre_len) // cyc_len)
        remain = sum(P[:pre_len + nxt_len])
        print(cyc + remain)
        exit()
    X[x] = True
    P.append(x)
    sum_p += x
    x = x*x % m
print(sum_p)
