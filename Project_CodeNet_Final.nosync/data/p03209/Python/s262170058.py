N, X = map(int, input().split())

def fac(n):
    if n == 0:
        return 1
    else:
        return 2 * fac(n-1) + 3

def rec(x, n, tmp):
    if n == 0:
        return tmp + 1
    m = fac(n)
    if x == 0:
        return tmp + 0
    elif x == m-1:
        return tmp + (m+1)//2
    elif x == (m-1)//2:
        return tmp + (m+3)//4
    elif 0 < x < (m-1)//2:
        return rec(x-1, n-1, tmp)
    else:
        return rec(x-(m+1)//2, n-1, tmp+(m+3)//4)

print(rec(X-1, N, 0))