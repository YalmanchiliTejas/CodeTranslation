def inpl(): return [int(i) for i in input().split()]
def burger(x):
    if not x:
        return 1
    return 3 + 2*burger(x-1)
def pate(n,x):
    if not n or not x:
        return [0, 1][x == 1]
    result = 0
    if x == burger(n):
        return 2**(n+1)-1
    if x == 2 + burger(n-1):
        return 2**n-1 + 1
    elif x > (burger(n)+1)//2:
        result += 2**n-1 + 1
        x -= (burger(n-1)+2)
    else:
        x -= 1
    return result + pate(n-1,x)      
N, X = inpl()
print(pate(N, X))