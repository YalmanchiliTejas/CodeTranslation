def resolve():
    n = int(input())
    a = tuple(map(int,input().split()))
    N = 10**9+7
    s = sum(a) % N
    ans = 0
    for i in a:
        s -= i
        ans += s*i
        ans %= N
    print(ans)
resolve()