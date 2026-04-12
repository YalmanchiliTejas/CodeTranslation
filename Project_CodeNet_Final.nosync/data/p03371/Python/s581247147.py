import sys
from collections import deque
import copy
def main():
    A, B, C, X, Y = map(int, input().split())
    C *= 2
    ans = 0
    if A + B >= C:
        if X > Y:
            ans = C * Y + min(A, C) * (X - Y)
        else:
            ans = C * X + min(B, C) * (Y - X)
    else:
        if X > Y:
            ans = min(A, C) * (X - Y) + A * Y + B * Y
        else:
            ans = A * X + B * X + min(B, C) * (Y - X)
    print(ans)


if __name__ == '__main__':
    main()
