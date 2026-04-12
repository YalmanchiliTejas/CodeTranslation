import sys
import bisect
import collections


def input():
    return sys.stdin.readline().rstrip()


def main():
    n = int(input())
    la = [int(input()) for _ in range(n)]
    result = collections.deque()
    for a in la:
        idx = bisect.bisect_left(result, a)
        if idx == 0:
            result.appendleft(a)
        else:
            result[idx - 1] = a
    print(len(result))


main()
