def resolve():
    import math
    A, B, C, X, Y = map(int, input().split())
    ans = []
    for i in range(max(X, Y)*2+1):
        ans.append(C*i + A*(max(X-i/2, 0)) + B*(max(Y-i/2, 0)))
    print(math.floor(min(ans)))
resolve()