from itertools import permutations
import sys
input = sys.stdin.readline

def main():
    N, M = map(int, input().split())
    link = [[False] * N for i in range(N)]
    for i in range(M):
        a, b = map(int, input().split())
        link[a-1][b-1] = True
        link[b-1][a-1] = True
    
    ans = 0
    for p in permutations(range(1, N)):
        # print(0, p)
        pre = 0
        ok = True
        for t in p:
            if not link[pre][t]:
                ok = False
                break
            pre = t
        if ok:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()