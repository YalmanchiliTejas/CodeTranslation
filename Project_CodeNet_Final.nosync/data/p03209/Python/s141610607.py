N, X = map(int, input().split())

n_all = [1] + [0] * N
n_p = [1] + [0] * N
for i in range(1, N + 1):
    n_all[i] = n_all[i - 1] * 2 + 3
    n_p[i] = n_p[i - 1] * 2 + 1
    
def f(l, x):
    if l == 0:
        return 0 if x <= 0 else 1
    if x <= 1:
        return 0
    elif x < n_all[l - 1] + 1:
        return f(l - 1, x - 1)
    elif x == n_all[l - 1] + 1:
        return n_p[l - 1]
    elif x < n_all[l - 1] * 2 + 2:
        return n_p[l - 1] + 1 + f(l - 1, x - n_all[l - 1] - 2)
    else:
        return n_p[l - 1] * 2 + 1
      
print(f(N, X))
