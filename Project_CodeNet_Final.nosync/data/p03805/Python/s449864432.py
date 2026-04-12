n, m = map(int, raw_input().split())
edges = [list(map(int, raw_input().split())) for _ in xrange(m)]

adjacent = [[] for _ in xrange(n)]
for a, b in edges:
    adjacent[a-1].append(b)
    adjacent[b-1].append(a)

check = [False]*n
check[0] = True
count = 0

def DFS(cn):
    global count
    if all(check):
        count += 1
        return 0
    for nn in adjacent[cn-1]:
        if check[nn-1] == True:
            continue
        else:
            check[nn-1] = True
            DFS(nn)
            check[nn-1] = False
    return 0

if __name__ == '__main__':
    DFS(1)
    print count