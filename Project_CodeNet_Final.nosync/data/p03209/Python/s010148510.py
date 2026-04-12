N, X = [int(a) for a in input().split(" ")]
numt = [1]*51
nump = [0]*51
for i in range(1,51):
    numt[i]=2*numt[i-1]+3
    nump[i]=2*nump[i-1]+1

def rec(n, i):
    if n==0:
        return 1
    if i==0:
        return 0
    elif i==numt[n]-1:
        return 2*nump[n]+1
    mid = numt[n]//2
    if i==mid:
        return 1+nump[n]
    elif i>mid:
        return rec(n-1, i-mid-1)+nump[n]+1
    else:
        return rec(n-1, i-1)
    
print(rec(N, X-1))