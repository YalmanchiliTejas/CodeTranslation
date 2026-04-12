N,K = map(int,input().split())
sum = 0
for b in range(1,N+1):
    q = N % b
    p = (N - q) //  b
    sum += p * max(0,b-K)
    sum += max(0,q-K+1)

if(K == 0):
    sum -= N
print(sum)