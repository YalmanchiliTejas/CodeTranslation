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
dd=defaultdict(int)
dd[N]=1
for i in range(A,B+1):
    nd=defaultdict(int)
    for gro,num in dd.items():
        nd[gro]+=num
        t=gro//i
        for k in range(C,min(t,D)+1):
            #print(i, gro, t)
            u=(table[gro] * rtable[gro - k * i] * pow(rtable[i],k,mod) * rtable[k] )%mod
            nd[gro - k*i] += num* u
            nd[gro - k * i]%=mod
    dd=nd
    #print(dd)
print(dd[0]%mod)
