import itertools

P = []
counter = 0
if __name__ == '__main__':
    N, M = map(int, input().split())
    P = [[0]*N for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        P[a-1][b-1] = P[b-1][a-1] = 1
    for v in itertools.permutations(range(N)):
        if v[0] != 0:
            break
        flag = 0
        for i in range(N - 1):
            if P[v[i]][v[i + 1]] == 0:
                flag = 1
                break
        if flag == 0:
            counter += 1
        
    print(counter)