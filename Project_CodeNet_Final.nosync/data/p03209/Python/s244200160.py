N, X = map(int, input().split())

# Level nバーガーの層数とパティの総数
burgers = [0] * (N + 1)
patty = [0] * (N + 1)
burgers[0] = 1
patty[0] = 1
for i in range(1, N + 1):
    burgers[i] = 3 + burgers[i - 1] * 2
    patty[i] = 1 + patty[i - 1] * 2


def f(n, x):
    if n == 0 and x == 1:
        return 1
    elif x == 1:
        return 0
    elif x < 2 + burgers[n - 1]:
        return f(n - 1, x - 1)
    elif x == 2 + burgers[n - 1]:
        return patty[n - 1] + 1
    elif x < burgers[n]:
        return patty[n - 1] + 1 + f(n - 1, x - 2 - burgers[n - 1])
    else:
        return patty[n]


print(f(N, X))