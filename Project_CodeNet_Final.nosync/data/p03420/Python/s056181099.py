N,K = map(int,input().split())
if K == 0:
    print(N**2)
    exit()
count = 0
for b in range(1,N+1):
    count += (N//b)*max(0,b-K) + max(N%b-K+1,0)
print(count)