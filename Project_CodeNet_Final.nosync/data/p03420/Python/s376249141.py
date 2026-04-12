N,K=map(int,input().split())
res=0
for b in range(1,N+1):
    if(b<=K):
        continue
    res+=(N//b)*(b-K)
    if(K!=0):
        res+=max(0,N%b-(K-1))
    else:
        res+=N%b
print(res)