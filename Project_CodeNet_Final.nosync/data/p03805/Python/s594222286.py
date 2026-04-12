import sys
input = sys.stdin.readline
from operator import itemgetter
import itertools

def main():
    n, m = map(int, input().strip().split())
    lis = [[] for _ in range(n)]
    visited = [-1] * n
    for _ in range(m):
        a, b = list(map(lambda x: x-1, map(int, input().strip().split())))
        lis[a].append(b)
        lis[b].append(a)
    
    ans = 0
    for path in itertools.permutations(range(n), n):
        if path[0] != 0:
            continue
        c = True
        for i in range(n-1):
            pi1 = path[i+1]
            pi = path[i]
            # print(path)
            if pi1 not in lis[pi]:
                c = False
                break
        if c:
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()
