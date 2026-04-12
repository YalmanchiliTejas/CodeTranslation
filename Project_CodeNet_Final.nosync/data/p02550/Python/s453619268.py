n, x, m = map(int, input().split())
P = [] # value of pre & cycle
sum_p = 0 # sum of pre + cycle
X = [-1] * m # for cycle check
for i in range(n):
    if X[x] > -1:
        cyc_len = len(P) - X[x]
        nxt_len = (n - X[x]) % cyc_len
        pre = sum(P[:X[x]])
        cyc = (sum_p - pre) * ((n - X[x]) // cyc_len)
        nxt = sum(P[X[x]: X[x] + nxt_len])
        print(pre + cyc + nxt)
        exit()
    X[x] = i
    P.append(x)
    sum_p += x
    x = x*x % m
print(sum_p)
