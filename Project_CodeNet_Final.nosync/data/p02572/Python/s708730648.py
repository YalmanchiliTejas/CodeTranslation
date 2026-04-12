def resolve():
    N = int(input())
    A = list(map(int, input().split()))
    Ans = 0
    C = 0
    for i in range(1, len(A)):
        C += A[i-1]
        Ans += A[i]*C % (10**9+7)
    print(Ans % (10**9 + 7))
    
resolve()    