N, X = map(int, input().split())
burger  = [1] * N
patty = [1] * N
for i in range(1, N):
    burger[i] = burger[i-1] * 2 + 3
    patty[i] = patty[i-1] * 2 + 1


def func(level, x):
    if level == 0:
        return 0 if x <= 0 else 1
    if burger[level-1] + 1 < x:
        return func(level-1, x-burger[level-1]-2) + patty[level-1] + 1
    else:
        return func(level-1, x-1)


print(func(N, X))
