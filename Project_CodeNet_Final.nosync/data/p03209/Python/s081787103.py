n, x = map(int, input().split())
def solve(n, i):
    if n==0:
        return 1
    if i==0:
        return 0
    if i<(2**(n+2)-3)//2:
        return solve(n-1, i-1)
    if i==(2**(n+2)-3)//2:
        return 2**n
    if i<2**(n+2)-4:
        return 2**n + solve(n-1, i-(2**(n+2)-3)//2-1)
    return 2**(n+1) - 1
print(solve(n, x-1))