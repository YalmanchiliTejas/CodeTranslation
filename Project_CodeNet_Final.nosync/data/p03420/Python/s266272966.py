N,K = list(map(int, input().split()))

# K b = K+1~N,a = ib+K total:sigma((N-k)//b+1)

if K==0:
        print(N*N)
else:
    ans = 0
    for b in range(K+1, N+1):
        ans += (N//b) * (b-K) + max(0, (N%b) - (K-1))
    print(ans)