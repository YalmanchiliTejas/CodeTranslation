N = int(input())
A = [-int(input()) for i in range(N)]

#weakly increase
def LIS(L):
    INF = float('inf')
    DP = [INF]*(N+1)

    def bisect(v):
        if v<DP[0]:
            return 0
        l = 0
        r = N
        while r-l>1:
            if v<DP[(l+r)//2]:
            #if v<=DP[(l+r)//2]:
                r = (l+r)//2
            else:
                l = (l+r)//2
        return r
    
    for v in L:
        DP[bisect(v)] = v
    return DP

DP = LIS(A)
count = 0
for i in range(N):
    if DP[i]<10**10:
        count+=1
    else:
        break
print(count)