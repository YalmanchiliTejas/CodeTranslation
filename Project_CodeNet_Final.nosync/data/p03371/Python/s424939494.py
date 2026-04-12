def resolve():
    A, B, C, X, Y = list(map(int, input().split()))
    ans = []
    for i in range(0, 100000+1):
        ans.append(i * 2 * C + max(0, X - i) * A + max(0, Y - i) * B)
    print(min(ans))
    return


resolve()