n = int(input())
a = list(map(int,input().split()))
mod =10**9+7
sd=0
sdd = 0
for i in a:
    sd+=i**2
    sdd +=i
    sd %= mod
    sdd %=mod
print((sdd**2-sd)*(5*10**8+4)%mod)