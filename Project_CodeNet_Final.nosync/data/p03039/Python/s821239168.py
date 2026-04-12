N, M, K = list(map(int, input().split()))
mod = 10**9 + 7

tn = 0
tm = 0

for n in range(N):
    tn = (tn + n*(n+1)//2) % mod
tn = tn*M*M % mod

for m in range(M):
    tm = (tm + m*(m+1)//2) % mod
tm = tm*N*N % mod

class combinationmod():
    def __init__(self, MAX, mod):
        self.mod = mod
        self.fac = [0]*(MAX+1)
        self.finv = [0]*(MAX+1)
        self.inv = [0]*(MAX+1)
        self.fac[0] = self.fac[1] = 1
        self.finv[0] = self.finv[1] = 1
        self.inv[1] = 1
        for i in range(2, MAX+1):
            self.fac[i] = self.fac[i-1]*i % mod
            self.inv[i] = (-self.inv[mod % i]*(mod//i)) % mod
            self.finv[i] = self.finv[i-1] * self.inv[i] % mod
    def nCk(self,n,k):
        if n<k or n<0 or k<0:
            return 0
        return self.fac[n]*(self.finv[k]*self.finv[n-k]%self.mod)%self.mod
 
c = combinationmod(200000,int(1e9+7))

ans = (tn + tm)*c.nCk(N*M-2, K-2) %mod
print(ans)