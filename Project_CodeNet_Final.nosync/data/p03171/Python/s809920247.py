def f(A):
    # Taro (X) first  maximize X
    # Jiro (Y) second maximize Y
    # choose: first OR last
    # [ n m p q] => X=max | n + F(i + 1 + 1, j) + F(i + 1, j - 1)
    #                     | q + F(i, j - 1 - 1) + F(i + 1, j - 1)
    n = len(A)
    dp = [ [(0, 0)] * n for _ in range(n) ]
    for b in range(n - 1, -1, -1):
        for e in range(b, n):
            L1, L2 = dp[b + 1][e] if b + 1 <= e else (0, 0)
            R1, R2 = dp[b][e - 1] if b <= e - 1 else (0, 0)
            if A[b] + L2 > A[e] + R2:
                dp[b][e] = (A[b] + L2, L1)
            else:
                dp[b][e] = (A[e] + R2, R1)
    X, Y = dp[0][n - 1]
    return X - Y

assert f([10, 80, 90, 30]) == 10
assert f([10, 100, 10]) == -80
assert f([1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1, 1000000000, 1]) == 4999999995
assert f([4, 2, 9, 7, 1, 5]) == 2
assert f([10]) == 10

n = input()
A = list(map(int, input().split()))
ans = f(A)
print(ans)
