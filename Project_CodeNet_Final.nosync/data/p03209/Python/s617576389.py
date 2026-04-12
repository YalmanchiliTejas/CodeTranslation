burgerLens = [1 + 4 * (1 - 2**i)/(1-2) for i in range(0,51)]
numPatties = [1 + 2 * (1 - 2**i)/(1-2) for i in range(0,51)]

def recurse(n,k):
    if n == 0:
        return numPatties[0]
    if k <= n:
        return 0
    
    mid = burgerLens[n] // 2 + 1
    if k == mid:
        return 1 + numPatties[n-1]
    if k < mid:
        return recurse(n-1,k-1)
    if k > mid:
        return 1 + numPatties[n-1] + recurse(n-1,k-2-burgerLens[n-1])
    
N,K = map(int,input().split())
print(int(recurse(N,K)))