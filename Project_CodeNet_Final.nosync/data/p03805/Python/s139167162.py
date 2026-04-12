from itertools import permutations

def int0(s):
    return int(s) - 1

def main():
    N, M = map(int, input().split())
    edges = [tuple(map(int0, input().split())) for _ in range(M)]

    to = [[False]*N for _ in range(N)]
    for a, b in edges:
        to[a][b] = True
        to[b][a] = True
    
    ans = 0
    for p in permutations(range(1, N)):
        if to[0][p[0]] and all(to[p[i]][p[i+1]] for i in range(N-2)):
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()