def solve(L, x):
    if L == 0:
        return 1
    elif x == 1 or x == 0:
        return 0
    elif (2**(L+2)-3)//2 >= x >= 2:
        return solve(L-1, x-1)
    elif x == (2**(L+2)-3)//2 +1:
        return (2**(L+1)-1)//2+1
    elif (2**(L+2)-3)//2+2 <= x <= (2**(L+2)-3):
        return 2**(L+1)-1-solve(L,(2**(L+2)-3)-x)

N, X = map(int, input().split())
print(solve(N, X))