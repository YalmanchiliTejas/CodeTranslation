N, M = map(int, input().split())

Map = [[] for _ in range(N)]
reached = [False]*N

for _ in range(M):
    aa, bb = map(int, input().split())
    Map[aa-1].append(bb-1)
    Map[bb-1].append(aa-1)

cnt = 0

def DFS(x):
    global cnt
    global reached

    reached[x] = True

    if all(reached):
        cnt += 1
        reached[x] = False

        return

    for i in Map[x]:
        if reached[i]:
            continue

        else:
            DFS(i)

    reached[x] = False


DFS(0)
print(cnt)
