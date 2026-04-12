n, x = map(int,input().split())
def ABC115D(n,x):
    if x == 0:
        return 0
    if n == 0:
        return 1
    elif x == 1:
        return 0
    elif x >= 2**(n+1)-1:
        return ABC115D(n-1,x-2**(n+1)+1) + 2**n
    else:
        return ABC115D(n-1,x-1)
print(ABC115D(n,x))