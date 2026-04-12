def f(n, x):
    if n == 0:
        return min(x, 3)
    elif x == 0:
        return 0
    elif 0 < x and x <= layers_num[n - 1]:
        return f(n - 1, x - 1)
    elif x == 1 + layers_num[n - 1]:
        return p[n - 1] + 1
    elif 1 + layers_num[n - 1] < x <= 1 + 2 * layers_num[n - 1]:
        return p[n - 1] + 1 + f(n - 1, x - 2 - layers_num[n - 1])
    else:
        return 2 * p[n - 1] + 1


level0 = 'BPPPB'
N, X = map(int, input().split())

layers_num = []
p = []
for n in range(N):
    if n == 0:
        layers_num.append(len(level0))
        p.append(level0.count('P'))
    else:
        layers_num.append(layers_num[n - 1] * 2 + 3)
        p.append(2 * p[n - 1] + 1)

print(f(N - 1, X - 1))
