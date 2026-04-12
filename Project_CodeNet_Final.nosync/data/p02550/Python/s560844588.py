n, x, m = map(int, input().split())
mn = min(n, m)
P = [] # pre_sum
sum_p = 0 # sum of pre + cycle
X = [-1] * m # for cycle check & pre_len
for i in range(mn):
    if X[x] > -1:
        cyc_len = len(P) - X[x]
        remain = P[X[x]]
        cyc = (sum_p - remain) * ((n - X[x]) // cyc_len)
        remain += P[X[x] + (n - X[x]) % cyc_len] - P[X[x]]
        print(cyc + remain)
        exit()
    P.append(sum_p)
    sum_p += x
    X[x] = i
    x = x*x % m
print(sum_p)
