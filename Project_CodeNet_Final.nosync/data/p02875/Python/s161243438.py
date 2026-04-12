#C
def main():
    mod=998244353
    n=int(input())
    Fact=[1] #階乗
    for i in range(1,n+1):
        Fact.append(Fact[i-1]*i%mod)
    Finv=[0]*(n+1) #階乗の逆元
    Finv[-1]=pow(Fact[-1],mod-2,mod)
    for i in range(n-1,-1,-1):
        Finv[i]=Finv[i+1]*(i+1)%mod
    def comb(n,r):
        if n<r:
            return 0
        return Fact[n]*Finv[r]*Finv[n-r]%mod
    
    impossible=0
    m=1
    for k in range(n//2):
        impossible+=comb(n,k)*m%mod
        impossible%=mod
        m*=2
        m%=mod
    print((pow(3,n,mod)-impossible*2)%mod)

if __name__=='__main__':
    main()