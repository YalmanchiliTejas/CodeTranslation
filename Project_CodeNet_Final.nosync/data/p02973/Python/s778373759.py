import sys
from collections import deque
from bisect import bisect_left

def main():
    input = sys.stdin.readline
    N = int(input())
    q = deque()
    for _ in range(N):
        a = int(input())
        pos = bisect_left(q, a)
        if pos == 0:
            q.appendleft(a)
        else:
            q[pos-1] = a

    return len(q)


if __name__ == '__main__':
    print(main())
