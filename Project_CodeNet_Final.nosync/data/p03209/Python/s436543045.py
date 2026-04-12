N, X = [int(x) for x in input().split()]
INF = 10**9

layer_num = [1]
p = [1]

for i in range(N):
    layer_num.append(layer_num[-1]*2+3)
    p.append(p[-1]*2+1)


def rec(n, x):
    if x == 0:
        return 0
    if n == 0:
        return 1
    elif x <= layer_num[n-1]+1:
        return rec(n-1, x-1)
    else:
        return p[n-1] + 1 + rec(n-1, x-(layer_num[n-1]+2))


print(rec(N, X))
