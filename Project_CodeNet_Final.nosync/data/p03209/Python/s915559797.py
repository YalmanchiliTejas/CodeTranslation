memo = [-1]*100
mepp = [-1]*100
def getPB(N,k):
    if (N==0):
        return 1,1 if k>0 else 0
    if (memo[N] != -1 and k >= memo[N] and mepp[N]!=-1 ):
        return memo[N] , mepp[N]
    if (memo[N] != -1 and k <= 0):
        return memo[N] , 0
    #c =  1+getPB(N-1)+1+getPB(N-1)+1 # BxPxB
    c,p = 1,0
    _c,_p=getPB(N-1,k-c)
    c,p=c+_c,p+_p
    c,p=c+1,(p+1 if (k-c>0) else p)
    _c,_p=getPB(N-1,k-c)
    c,p=c+_c,p+_p
    c += 1
    memo[N] = c
    if (k-c>=0):
        mepp[N] = p
    return c,p
N,X = [ int(it) for it in input().split() ]
print ( getPB(N,X)[1] )