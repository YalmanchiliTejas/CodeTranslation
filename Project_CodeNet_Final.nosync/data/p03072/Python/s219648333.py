def resolve():
    N = int(input())
    H = [int(i) for i in input().split()]
    ans = 0
    maxH = 0
    for i in range(N):
        if H[i] >= maxH:
            ans += 1
            maxH = H[i]
    print(ans)


resolve()
