N, X = map(int,input().split())

def keisan(n,x):
    if n == 1:
        if x <= 1:
            return 0
        elif 2 <= x <= 4:
            return x-1
        else:
            return 3
    if x <= 1:
        return 0
    elif 1 < x <= 2**(n+1) - 2:
        return keisan(n-1,x-1)
    elif x == 2**(n+1) - 1:
        return 2**n
    else:
        return 2**n + keisan(n-1,x-(2**(n+1)-1))

print(keisan(N,X))
