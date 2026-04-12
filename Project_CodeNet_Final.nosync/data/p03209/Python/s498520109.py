n, x = list(map(int, input().split()))

def b_size(N): #バーガーの大きさ
    return 2 ** (N+2) - 3

def p_num(N): #そのレベルのパティの数
    return 2 ** (N+1) - 1

def f(level, X):
    if X == 0:
        return 0

    if level == 0:
        return 1

    if X <= b_size(level-1)+1:
        return f(level-1, X-1)
    else:
        return p_num(level-1) + f(level-1, X-b_size(level-1)-2) + 1

print(f(n, x))