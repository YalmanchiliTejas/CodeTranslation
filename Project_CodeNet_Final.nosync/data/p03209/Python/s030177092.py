def ans(n,x):
    if n == 1:
        if x == 1:
            return 0
        elif x == 2:
            return 1
        elif x == 3:
            return 2
        else:
            return 3
    else:
        if x == 1:
            return 0
        if 2 <= x <= 2**(n+1) -2:
            return ans(n-1,x-1)
        if x == 2**(n+1) -1:
            return 2**n - 1 + 1
        if 2**(n+1) <= x <= 2**(n+2) -4:
            return 2**n - 1 + 1 + ans(n-1,x-2**(n+1)+1)
        else:
            return 2 * (2**n - 1) + 1
        
N, X = map(int,input().split())

print(ans(N,X))