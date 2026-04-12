n, x, m = map(int, input().split())
mn = min(n, m)
P = [] # value of pre & cycle
sum_p = 0 # sum of pre + cycle
X = [-1] * m # for cycle check
for i in range(mn):
    if X[x] > -1:
        pre_len = X[x]
        cyc_len = len(P) - pre_len
        nxt_len = (n - pre_len) % cyc_len
        pre = sum(P[:pre_len])
        cyc = (sum_p - pre) * ((n - pre_len) // cyc_len)
        nxt = sum(P[pre_len: pre_len + nxt_len])
        print(pre + cyc + nxt)
        exit()
    X[x] = i
    P.append(x)
    sum_p += x
    x = x*x % m
print(sum_p)
