# coding: utf-8
# Your code here!

N,K=map(int,input().split())

ans=0
for n in range(K+1,N+1):
    coff=(n)-(K)
    quan=(N)//n
    ans+=coff*quan
    temp=N-quan*n
    if K!=0:
        temp-=(K-1)
    
    ans+=max(temp,0)
    #print(n,coff,quan,max(temp,0))

print(ans)