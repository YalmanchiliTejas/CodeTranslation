N = int(input())
As = list(map(int, input().split()))
d = [0]*(N**2)
for i in range(N):
    for j in range(N-i):
        span = i*N+j
        if i == 0:
            d[span] = As[j]
        else:
            d[span] = max(As[j]-d[span-N+1], As[j+i]-d[span-N])
print(d[span])