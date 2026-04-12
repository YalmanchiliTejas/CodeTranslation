# input here
_INPUT = """\
4
141421356 17320508 22360679 244949
"""
"""
K = int(input())
H, W, K = map(int, input().split())
a = list(map(int, input().split()))
xy = [list(map(int, input().split())) for i in range(N)]
p = tuple(map(int,input().split()))
"""
def main():
    n = int(input())
    a = list(map(int, input().split()))
    cumsum = list(itertools.accumulate(a))

    sum1 = 0
    for i in range(len(a)):
        mult = a[i] * (cumsum[n-1] - cumsum[i])
        sum1 += mult

    print((sum1 % (10**9 + 7)))


if __name__ == '__main__':
    import io
    import sys
    import math
    import itertools
    from collections import deque

    # sys.stdin = io.StringIO(_INPUT)
    main()