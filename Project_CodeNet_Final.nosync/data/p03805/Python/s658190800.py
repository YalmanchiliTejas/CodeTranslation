import sys
from itertools import permutations
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    link = [[False] * N for i in range(N)]

    for i in range(M):
        a, b = map(int, input().split())
        link[a-1][b-1] = True
        link[b-1][a-1] = True
    
    ans = 0
    path = [i for i in range(1, N)]
    for p in permutations(path):
        if link[0][p[0]]:
            ok = True
            for i in range(N-2):
                if not link[p[i]][p[i+1]]:
                    ok = False
                    break
            if ok:
                ans += 1
    print(ans)

if __name__ == "__main__":
    main()