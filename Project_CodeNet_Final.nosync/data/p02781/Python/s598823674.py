
def cmb(n, r):
    if n - r < r:
        r = n - r
    if r == 0:
        return 1
    if r == 1:
        return n

    numerator = [n - r + k + 1 for k in range(r)]
    denominator = [k + 1 for k in range(r)]

    for p in range(2, r+1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p-1, r, p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot

    result = 1
    for k in range(r):
        if numerator[k] > 1:
            result *= int(numerator[k])
            #print(result)
            result %= (10**9+7)

    return result


def f(x,k,small):    
    d = len(x)
    #print(x, k, d,small)
    if d == 0:        
        if k==0:
            return 1
        else:   
            return 0
    #if d==1 and k==0:
    #    return 0 
    if d<k:
        return 0

    if k==0:
        return 1

    #if d==1:
    #    return x[0]

    if small:
        #print(k,d)
        return (9**(k))*cmb(d, k)

    #A = max(x[0]-1, 0)
    if x[0]==0:
        return f(x[1:],k,False)
    zero = f(x[1:],k,True)
    aida=f(x[1:],k-1,True)*(x[0]-1)
    eq = f(x[1:], k-1,False)
    #print(zero,aida,eq)
    return zero+aida+eq

N=list(map(int,list(input())))
K=int(input())

print(f(N,K,False))

#dp0[i][j]=x[0]*dp0[i][j]+dp1[i+1][j]

