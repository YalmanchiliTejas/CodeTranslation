N, K = map(int,input().split())
total = 0
num = 1
for i in range(K+1,N+1):
    total += N//i*num
    num += 1
    if K == 0:
        total += max(N%i-K,0)
    else:        
        total += max(N%i-K+1,0)

print(total)