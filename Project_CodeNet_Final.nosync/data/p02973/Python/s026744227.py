import bisect
from collections import deque
from sys import stdin


def main():
    N = int(stdin.readline().rstrip())
    As = [int(stdin.readline().rstrip()) for x in range(N)]
    dq = deque([])
    for A in As:
        idx = bisect.bisect_left(dq, A)
        if idx == 0:
            dq.appendleft(A)
        else:
            dq[idx - 1] = A
    print(len(dq))


if __name__ == "__main__":
    main()
