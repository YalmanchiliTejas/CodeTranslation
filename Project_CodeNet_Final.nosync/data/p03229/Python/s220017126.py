from collections import deque
import sys
input = sys.stdin.readline


def solve(N, A, fromR=True):
    res = 0
    L, R = None, None

    while A:
        fromR = 1 - fromR

        if L is None:
            L = A.pop() if fromR else A.popleft()
            R = L
            continue

        if len(A) > 1:
            if fromR:
                x = A.pop()
                y = A.pop()
            else:
                x = A.popleft()
                y = A.popleft()
            res += abs((R + L) - (x + y))
            R, L = x, y
            continue

        if len(A) == 1:
            x = A.pop()
            res += max(abs(R - x), abs(L - x))
            continue

    return res


if __name__ == "__main__":
    N = int(input())
    A = sorted([int(input()) for _ in range(N)])
    B = deque(A[::])
    A = deque(A)
    

    ans1 = solve(N, A, 0)
    ans2 = solve(N, B, 1)
    ans = max(ans1, ans2)
    print(ans)
