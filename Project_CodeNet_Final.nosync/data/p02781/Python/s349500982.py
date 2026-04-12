def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**7)
    from collections import Counter, deque
    #from collections import defaultdict
    from itertools import combinations, permutations, accumulate, groupby, product
    from bisect import bisect_left,bisect_right
    from heapq import heapify, heappop, heappush
    import math

    #inf = 10**17
    mod = 10**9 + 7
    def ncr(n, r, mod):
        r = min(r, n-r)
        numer = denom = 1
        for i in range(1, r+1):
            numer = numer * (n+1-i) % mod
            denom = denom * i % mod
        return numer * pow(denom, mod-2, mod) % mod

    n = input().rstrip()
    k = int(input())
    ln = len(n)
    if ln < k:
        print(0)
        exit()
    res = 0
    if k == 1:
        if ln >= 2:
            res += ncr(ln-1, 1, mod) * 9
        res += int(n[0])
    if k == 2:
        if ln >= 3:
            res += ncr(ln-1, 2, mod) * (9**k)
        res += ncr(ln-1, 1, mod) * 9 * (int(n[0])-1)
        for i in range(1, ln):
            if n[i] != '0':
                if i == ln-1:
                    res += int(n[i])
                else:
                    res += ncr(ln-i-1, 1, mod) * 9
                    res += int(n[i])
                break
    if k == 3:
        if ln >= 4:
            res += ncr(ln-1, 3, mod) * (9**k)
        res += ncr(ln-1, 2, mod) * 81 * (int(n[0])-1)
        for i in range(1, ln-1):
            if n[i] != '0':
                if ln-i-1 >= 2:
                    res += ncr(ln-i-1, 2, mod) * 81
                res += ncr(ln-i-1, 1, mod) * 9 * (int(n[i])-1)
                for j in range(i+1, ln):
                    if n[j] != '0':
                        if j != ln-1:
                            res += ncr(ln-j-1, 1, mod) * 9 
                        res += int(n[j])
                        break
                break
    print(res)

if __name__ == '__main__':
    main()