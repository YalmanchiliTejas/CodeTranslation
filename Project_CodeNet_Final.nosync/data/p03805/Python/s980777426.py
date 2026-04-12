import itertools

def resolve():
    n, m = map(int, input().split())
    S = [[0]*n for i in range(n)]

    for i in range(m):
        a, b = map(int, input().split())
        S[a-1][b-1] = 1
        S[b-1][a-1] = 1

    ans = 0
    for p in itertools.permutations(range(n)):
        if p[0] != 0:
            break
        tmp = 1
        for i in range(n-1):
            tmp *= S[p[i]][p[i+1]]
        ans += tmp

    print(ans)

if __name__ == '__main__':
    resolve()