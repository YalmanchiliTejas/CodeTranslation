N = int(input())
A = list(map(int, input().split()))
mod = int(1e9+7)

all = pow(sum(A), 2, mod=mod)%mod
d = 0
for a in A:
    d += pow(a,2)
    d = d%mod

print(int((all-d)*pow(2, mod-2, mod=mod))%mod)
