n, x = map(int, input().split())
def layer(n):
    return 2 ** (n+2) - 3
def full(n):
    return 2 ** (n+1) - 2
def solve(n, x):
    if x <= 0:
        return 0
    if n == 0:
        return 0
    if x >= layer(n):
        return full(n)
    if x <= layer(n-1) + 1:
        return 1 + solve(n-1, x-1)
    else:
        return full(n-1) + solve(n-1, x - layer(n-1) - 2) + 1
print(x - solve(n,x))
