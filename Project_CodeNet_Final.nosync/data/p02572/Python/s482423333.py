N  = int(input())
A  = list(map(int,input().split()))

ttl = sum(A)
ttl -= A[0]

ans = 0
mod= 10**9+7
for i in range(len(A)-1):
    ans += A[i]*ttl
    ttl %= mod
    ans %= mod
    ttl -= A[i+1]
    # print(ans,ttl)
print(ans)


