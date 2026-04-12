N=int(input())
a=[int(i) for i in input().split()]
mod=10**9+7
S=sum(a)%mod
T=sum([i*i for i in a])%mod
print((pow(2,mod-2,mod)*(S*S-T))%mod)
