A, B, C, X, Y = map(int, input().split())
def calc(x, y):
    return A*x+B*y

mi = min(X, Y)
ma = max(X, Y)
print(min(calc(X,Y), calc(X-mi, Y-mi) + C*mi*2, C*ma*2))