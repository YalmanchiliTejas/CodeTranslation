def inpl(): return [int(i) for i in input().split()]

def alll(x):
    if not x:
        return 1
    return 3+2*alll(x-1)
def pate(n,x):
    if n == 0:
        return [0, 1][x == 1]
    result = 0
    if x == 0:
        return 0
    if x == alll(n):
        return 2**(n+1)-1
    if x == 2 + alll(n-1):
        return 2**n-1 + 1
    elif x > (alll(n)+1)//2:
        result += 2**n-1 + 1
        x -= (alll(n-1)+2)
    else:
        x -= 1
    return result + pate(n-1,x)      
N, X = inpl()
print(pate(N, X))