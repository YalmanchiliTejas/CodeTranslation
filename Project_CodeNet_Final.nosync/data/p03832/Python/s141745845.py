from collections import defaultdict
N,A,B,C,D=map(int,input().split())

mod=10**9+7
table=[1]*(N+3)
t=1
for i in range(1,N+3):
    t*=i
    t%=mod
    table[i]=t
rtable=[1]*(N+3)
t=1
for i in range(1,N+3):
    t*=pow(i,mod-2,mod)
    t%=mod
    rtable[i]=t
dp=defaultdict(int)
dp[N]=1
for l in range(A,B+1):
    ndp=defaultdict(int)
    for mem,num in dp.items():
        ndp[mem]+=num
        for k in range(C,D+1):
            if mem-k*l<0:
                break
            t=(table[mem]*pow(rtable[l],k,mod)*rtable[mem-k*l]*rtable[k])%mod
            ndp[mem-k*l]+=(num*t)%mod
            ndp[mem-k*l]%mod
            #print(mem-k*l,(num*t)%mod)

    dp=ndp
    #print(dp)
print(dp[0]%mod)