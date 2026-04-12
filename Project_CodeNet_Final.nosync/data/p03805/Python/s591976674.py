import sys,os
from collections import defaultdict, deque
from math import ceil, floor
import itertools
if sys.version_info[1] >= 5:
    from math import gcd
else:
    from fractions import gcd
sys.setrecursionlimit(10**6)
write = sys.stdout.write
dbg = (lambda *something: print(*something)) if 'TERM_PROGRAM' in os.environ else lambda *x: 0
def main(given=sys.stdin.readline):
    input = lambda: given().rstrip()
    LMIIS = lambda: list(map(int,input().split()))
    II = lambda: int(input())
    MOD = 10**9+7

    N,M = LMIIS()
    edges = defaultdict(list)
    for i in range(M):
        a,b = LMIIS()
        edges[a].append(b)
        edges[b].append(a)
    ans = 0
    for l in itertools.permutations(range(2,N+1), N-1):
        prev = 1
        for v in l:
            if v in edges[prev]:
                prev = v
            else:
                break
        else:
            ans += 1
    print(ans)




if __name__ == '__main__':
    main()