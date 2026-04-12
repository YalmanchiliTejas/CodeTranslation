n, x, m = map(int, input().split())
mn = min(n, m)
P = [] # (x,pre_sum)
sum_p = 0 # sum of pre + cycle
X = [-1] * m # for cycle check
for i in range(mn):
    if X[x] > -1:
        cyc_len = len(P) - X[x]
        pre = P[X[x]][1]
        cyc = (sum_p - pre) * ((n - X[x]) // cyc_len)
        nxt = P[X[x] + (n - X[x]) % cyc_len][1] - P[X[x]][1]
        print(pre + cyc + nxt)
        exit()
    P.append([x, sum_p])
    sum_p += x
    X[x] = i
    x = x*x % m
print(sum_p)
