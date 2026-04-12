from itertools import permutations
def main():
    N, M = map(int, input().split())
    l = [[0] * N for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        l[a][b] = 1
        l[b][a] = 1
    r = 0
    for x in permutations(range(1, N)):
        if l[0][x[0]] == 0:
            continue
        for i in range(N-2):
            if l[x[i]][x[i+1]] == 0:
                break
        else:
            r += 1
    return r
print(main())
    
