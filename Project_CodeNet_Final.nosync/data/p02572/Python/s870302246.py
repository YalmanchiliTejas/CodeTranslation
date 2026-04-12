n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
s=sum(a)%mod

aa=sum([i**2 for i in a])%mod

def mul(a, b):
    return ((a % mod) * (b % mod)) % mod

def div(a, b):
    return mul(a, pow(b, mod-2,mod)) % mod

ans=div((pow(s,2)%mod-aa)%mod,2)

print(int(ans))