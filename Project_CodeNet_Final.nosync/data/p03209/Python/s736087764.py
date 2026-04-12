import numpy as np

N, X = list(map(int, input().split(" ")))

a = 1
p = 1
a_list = [1]
p_list = [1]
for i in range(N+1):
    a = 2 * a + 3
    p = 2 * p + 1
    a_list.append(a)
    p_list.append(p)


def f(N, X):
    ai_1 = a_list[N-1]
    if N == 1:
        if 1 <= X and X <= 4:
            out = X - 1
        else: 
            assert X == 5
            out = 3
    elif X == 1:
        out = 0
    elif 2 <= X and X <= 1+ai_1:
        out = f(N-1, X-1)
    elif X == 2 + ai_1:
        out = p_list[N-1] + 1
    elif 3 + ai_1 <= X and X <= 2 + 2*ai_1:
        out = p_list[N-1] + 1 + f(N-1, X - 2 - a_list[N-1])
    else:
        assert X == 3+ 2*ai_1
        out = p_list[N]
    return out


print(f(N, X))