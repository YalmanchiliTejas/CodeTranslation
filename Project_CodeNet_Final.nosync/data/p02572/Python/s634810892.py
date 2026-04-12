N=int(input())
*A, = map(int,input().split())

mod = 10**9+7

ans = ((sum(A)%mod)**2)%mod
ans -= sum(a*a%mod for a in A)%mod
ans %= mod
ans *= pow(2,mod-2,mod)
ans %= mod

print(ans)