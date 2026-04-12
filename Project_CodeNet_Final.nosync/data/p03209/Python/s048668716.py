import sys
n, x = [int(i) for i in sys.stdin.readline().split()]
cur = 1
p = 1
ls = [cur]
p_ls = [p]
for i in range(50):
    cur = cur * 2 + 3
    p = p * 2 + 1
    ls.append(cur)
    p_ls.append(p)

def f(n, x):
    if n == 0:
        return 0 if x <= 0 else 1
    if x == 1:
        return 0
    elif x <= 1 + ls[n-1]:
        return f(n-1, x-1)
    elif x == ls[n-1] + 2:
        return 1 + p_ls[n-1]
    elif x < ls[n]:
        return 1 + p_ls[n-1] + f(n-1, x - ls[n-1] - 2)
    else:
        return p_ls[n]
res = f(n, x)
print(res)