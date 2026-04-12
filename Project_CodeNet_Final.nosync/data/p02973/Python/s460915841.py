from sys import stdin, setrecursionlimit
from collections import deque
from bisect import bisect_left


def main():
    input = stdin.buffer.readline
    n = int(input())
    a = [int(input()) for _ in range(n)]
    ans = deque()
    for ai in a:
        idx = bisect_left(ans, ai)
        if idx == 0:
            ans.appendleft(ai)
        else:
            ans[idx - 1] = ai

    print(len(ans))


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
