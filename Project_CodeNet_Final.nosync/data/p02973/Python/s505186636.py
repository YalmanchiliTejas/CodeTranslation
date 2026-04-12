import sys
from collections import deque
from bisect import bisect_left

def main():
    input = sys.stdin.readline
    N = int(input())
    a = int(input())
    q = deque()
    q.append(a)
    ans = 1
    for _ in range(N-1):
        n = int(input())
        if n <= q[0]:
            q.appendleft(n)
            ans += 1
            continue

        if n > q[-1]:
            q[-1] = n
            continue

        pos = bisect_left(q, n)
        q[pos-1] = n
        min_ = q[0]

    return ans


if __name__ == '__main__':
    print(main())
