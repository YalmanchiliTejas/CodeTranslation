N, X = [int(i) for i in input().split(' ')]

def f(n):
    return 4 * pow(2, n) - 3
def g(n):
    return pow(2, n+1) - 1

def ss2(k, n):
    if n == 0:
        return 1
    nn = f(n)
    cc = (nn//2) + 1
    if k == 1:
        return 0
    if k >= nn:
        return g(n) 
    elif k == cc:
        return g(n-1) + 1  
    elif k > cc:
        return g(n-1) + 1 + ss2(k-cc, n-1)
    elif k < cc:
        return ss2(k-1, n-1)

print(ss2(X, N))


