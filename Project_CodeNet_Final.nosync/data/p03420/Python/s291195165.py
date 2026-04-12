N,K = map(int,input().split())

ans = 0

c = 0

for i in range(K+1,N+1) :
    c += 1
    d = min(N,N-(K-1))

    while d > 0 :
        ans += min(d,c)
        d -= c
        d -= K

print(ans)
    