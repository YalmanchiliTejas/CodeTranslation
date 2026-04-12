MOD = 10**9+7

n = int(input())
a = list(map(int,input().split()))

asum = sum(a) % MOD
asq  = sum(x*x %MOD for x in a) %MOD

ans = (asum*asum - asq) %MOD * pow(2,MOD-2,MOD) %MOD
print(ans)