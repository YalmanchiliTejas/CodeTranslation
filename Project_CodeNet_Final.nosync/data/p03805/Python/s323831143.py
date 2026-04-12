import copy

n, m = map(int, input().split())

x = [[0 for _ in range(n)] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    x[a][b] = 1
    x[b][a] = 1

temp = []

def trace(p, route):
    hoge = copy.deepcopy(route)
    hoge.append(p)
    ret = 0
    for i in range(n):
        if i not in hoge and x[p][i] == 1:
            if len(hoge) == n - 1:
                return 1
            else:
                ret += trace(i, hoge)
    return ret

print(trace(0, temp))