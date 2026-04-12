import sys
import math
import itertools
import collections
from collections import deque

sys.setrecursionlimit(1000000)
MOD = 10 ** 9 + 7
input = lambda: sys.stdin.readline().strip()

NI = lambda: int(input())
NMI = lambda: map(int, input().split())
NLI = lambda: list(NMI())
SI = lambda: input()

def main():
    N, M = NMI()
    ab = [NLI() for _ in range(M)]
    
    l = [n for n in range(2,N+1)]
    
    per_list = list(itertools.permutations(l))
    ans = 0
    for p in range(len(per_list)):
        ls_p = list(per_list[p])
        ls_p.insert(0,1)
        
        flg = True
        for n in range(N-1):
            if not [min(ls_p[n],ls_p[n+1]),max(ls_p[n],ls_p[n+1])] in ab:
                flg = False
                continue
        else:
            if flg == True:
                ans += 1

    print(ans)


if __name__ == '__main__':
    main()