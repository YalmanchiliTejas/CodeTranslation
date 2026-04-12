def resolve():
    n = int(input())
    h = list(map(int, input().split()))
    ans = 1
    min = h[0]
    for i in range(1, n):
        if h[i] >= min:
            ans += 1
            min = h[i]
    print(ans)
resolve()