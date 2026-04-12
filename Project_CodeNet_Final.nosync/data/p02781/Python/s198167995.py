N = int(input())
K = int(input())

def solve(n,k):
    if k==0: return 1
    if n < 10:
        return n if k==1 else 0
    if n < 100 and k == 3:
        return 0
    m,d = divmod(n,10)
    ret = d * solve(m,k-1)
    ret += (9-d)*solve(m-1,k-1)
    ret += solve(m,k)
    return ret

print(solve(N,K))