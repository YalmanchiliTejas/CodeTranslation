def main():
    from builtins import int, str, map, list, dict, float, print, len, sorted, max, min
    from itertools import accumulate, permutations, combinations
    from collections import deque, defaultdict, Counter
    from operator import itemgetter
    from bisect import bisect_left, bisect_right, bisect
    from heapq import heappop, heappush
    from fractions import gcd
    import sys, re, math, copy
    sys.setrecursionlimit(10 ** 6)

    input = sys.stdin.readline
    input_str = (lambda: input().rstrip())
    input_list = (lambda: input().rstrip().split())
    input_number = (lambda: int(input()))
    input_number_list = (lambda: list(map(int, input_list())))

    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    N = input_number()
    S = [None] * N
    for i in range(N):
        S[i] = list(input_str())

    ans = ""
    for c in alphabet:
        t = 10**9
        for i in range(N):
            t = min(t,int(Counter(S[i])[c]))
        ans += c*t
    print(ans)

if __name__ == '__main__':
    main()
