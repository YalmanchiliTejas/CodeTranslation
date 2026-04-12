N=int(input())
mod=998244353

FACT=[1]
for i in range(1,N+1):
    FACT.append(FACT[-1]*i%mod)

FACT_INV=[pow(FACT[-1],mod-2,mod)]
for i in range(N,0,-1):
    FACT_INV.append(FACT_INV[-1]*i%mod)

FACT_INV.reverse()

POW=[1]
for i in range(N):
    POW.append(POW[-1]*2%mod)

def Combi(a,b):
    return FACT[a]*FACT_INV[b]*FACT_INV[a-b]%mod

SC=0
for i in range(N//2+1,N+1):
    SC+=Combi(N,i)*POW[N-i]

print((pow(3,N,mod)-SC*2)%mod)