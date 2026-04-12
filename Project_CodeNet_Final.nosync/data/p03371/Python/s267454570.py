import sys
stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)

i_i = lambda: int(i_s())
i_l = lambda: list(map(int, stdin.readline().split()))
i_s = lambda: stdin.readline().rstrip()

A, B, C, X, Y = i_l()

if X < Y:
    X * C + (Y - X) * B
    print(min((X * A + Y * B), (X * C * 2 + (Y - X) * B), C * max(X, Y) * 2))
else:
    print(min((X * A + Y * B), (Y * C * 2 + (X - Y) * A), C * max(X, Y) * 2))
    