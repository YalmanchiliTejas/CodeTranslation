N,K=map(int,input().split())
#N=10
#K=0
s=0

if(K==0):
    print(N**2)
    exit()

for b in range(K,N+1):
    s+=(b-K)*(N//b)
    s+=max(0,N-b*(N//b)-K+1)

print(s)
