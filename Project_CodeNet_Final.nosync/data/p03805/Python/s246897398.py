import sys
from math import *
from collections import deque, Counter, defaultdict
from fractions import gcd
from itertools import permutations
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return


def main():
    n,m = map(int, input().split())
    graph = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(m):
        a,b = map(int, input().split())
        graph[a-1][b-1] = 1
        graph[b-1][a-1] = 1
    # n!通りの並べ方があり，各並べ方について成立するかどうかを調べる．
    # 成立しないと判明した時点で探索をやめる
   
    a = [i+1 for i in range(n)]
    p = permutations(a)

    def check(x):
        # x: (1,3,4,6,7,2)
        for i in range(n-1):
            if not graph[x[i]-1][x[i+1]-1]:
                return False
        return True
    cnt = 0
    for x in p:
        if x[0] != 1:
            continue
        if check(x):
            cnt += 1       
    print(cnt)
    return

if __name__ == '__main__':
    main()