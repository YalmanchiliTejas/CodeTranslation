N, M = map(int, input().split())

road = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    road[a].append(b)
    road[b].append(a)

counter = 0
    
def search(pointStack):
    global counter
    if len(pointStack) == N:
        counter += 1
        pointStack.pop()
        return
    
    currentNode = pointStack[-1]
    for nextNode in road[currentNode]:
        if nextNode in pointStack:
            continue
        pointStack.append(nextNode)
        search(pointStack)

    pointStack.pop()

search([0])

print(counter)