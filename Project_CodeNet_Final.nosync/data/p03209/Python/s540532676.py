def f(n, x):
    if n == 0:
        return 1
    len_ = 2**(n+1) - 3
    num = 2**(n) - 1
    if x == 1:
        return 0
    elif x <= len_ + 1:
        return f(n-1, x-1)
    elif x == len_ + 2:
        return num + 1
    elif x <= (len_ + 1) * 2:
        return num + 1 + f(n-1, x-len_-2)
    else:
        return num * 2 + 1

n, x = map(int, input().split())

print(f(n,x))
