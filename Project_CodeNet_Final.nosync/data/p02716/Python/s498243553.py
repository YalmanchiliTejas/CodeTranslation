import sys

sys.setrecursionlimit(10**6)

def solve(n,a):
    wa=0
    for i in range(n):
        if(i%2==0):
            wa+=a[i]
    kotae=wa
    for i in range(n//2):
        wa+=a[(n//2-i-1)*2+1]
        wa-=a[(n//2-i-1)*2]
        if(wa>kotae):
            kotae=wa
    return kotae

def dfs(n,a,k):
    global zen
    zen.append([n,k])
    if(k==1):
        return max(a)
    ari=a[n-1]+dfs(n-2,a[:n-2],k-1)
    if(n==k*2-1):
        return ari
    nasi=dfs(n-1,a[:n-1],k)
    return max(ari,nasi)

n=int(input())

a=list(map(int,input().split()))

if(n%2==0):
    print(solve(n,a))
else:
    data=[[a[0],a[0]],[max(a[:2]),max(a[:2])]]
    #data.append([max(a[:3]),sum(a[:3])-min(a[:3])])
    data.append([max(a[:3]),a[0]+a[2]])
    for i in range(3,n):
        if(i%2==1):
            ari=a[i]+data[i-2][0]
            nasi=data[i-1][1]
            saiyo=max(ari,nasi)
            data.append([saiyo,saiyo])
        else:
            ooi=a[i]+data[i-2][1]
            nasi=data[i-1][1]
            ari=a[i]+data[i-2][0]
            sukunai=max(ari,nasi)
            data.append([sukunai,ooi])
    print(data[n-1][0])