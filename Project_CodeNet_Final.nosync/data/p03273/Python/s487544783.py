h, w = map(int, input().split())

newGrid = []
for i in range(h):
    a = list(input())
    for j,a_j in enumerate(a):
        if a_j == "#":
            newGrid.append(a)
            break
        else:
            continue

ans = []
for j in range(w):
    for i in range(len(newGrid)):
        if newGrid[i][j] == "#":
            ans.append([newGrid[k][j] for k in range(len(newGrid))])
            break
        else:
            continue
            
for ansi in list(zip(*ans)):
    print("".join(ansi))