N=int(input())
T=list(map(int,input().split()))

mod=(10**9)+7

goukei=0
S=[]
tmp=0
for i in range(N):
    tmp+=T[i]
    S.append(tmp)

for i in range(N-1):
    
    #print(T[i]*(S[N-1]-S[i]))
    goukei+=(T[i]*(S[N-1]-S[i]))
goukei=goukei%mod
print(goukei)