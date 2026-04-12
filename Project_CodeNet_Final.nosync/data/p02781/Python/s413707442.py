N = input()
K = int(input())

def comb(n,k):
    if k==0:
        return 1
    if k==1:
        return n
    if k==2:
        return (n*(n-1))//2
    if k==3:
        return (n*(n-1)*(n-2))//6

def rec(n,k):
    res = 0
    if k < 0:
        return res
    if k==0:
        res = 1
        return res
    if len(n)<k:
        return res
    if n[0] != '0':
        res += rec(n[1:],k-1)
        res += (int(n[0])-1)*comb(len(n)-1,k-1)*9**(k-1)
        res += comb(len(n)-1,k)*9**k
    else:
        res += rec(n[1:],k)
    return res

print(rec(N,K))