def resolve():
    N = int(input())
    A = list(map(int,input().split()))
    md = 10**9+7

    S = list(reversed(A))

    for i in range(1,N):
        S[i] = (S[i-1]+S[i])%md
    
    S.reverse()

    ans = 0
    for i in range(N-1):
        ans += (A[i]*S[i+1])%md
        ans %= md
    print(ans)
resolve()