N, X = map(int, input().split())
num_p = [2**(i+1)-1 for i in range(N+1)]
num_layer = [2**(i+2)-3 for i in range(N+1)]
def f(N, X):
    if N == 0:
        if X == 0:
            return 0
        else:
            return 1
    elif X == 1:
        return 0
    elif X <= 1 + num_layer[N-1]:
        return f(N-1, X-1)
    elif X == 2 + num_layer[N-1]:
        return 1 + num_p[N-1]
    elif X < 2 + 2 * num_layer[N-1]:
        return num_p[N-1] + 1 + f(N-1, X - 2 - num_layer[N-1])
    else:
        return 2 * num_p[N-1] + 1
print(f(N, X))