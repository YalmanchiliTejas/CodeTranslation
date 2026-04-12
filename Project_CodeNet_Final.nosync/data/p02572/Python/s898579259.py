def resolve():
    N = int(input())
    A = list(map(int, input().split()))
    S = sum(A)
    count = S
    ans = 0
    for i in A:
        count -= i
        ans += count*i
        if ans > 10**9+7:
            ans %= (10**9+7)
    print(ans)
resolve()