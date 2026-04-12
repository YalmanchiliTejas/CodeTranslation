import copy


def search(start, adj, stack):
    nextNum = 0
    start[1][start[0]] = 1
    for i in range(len(adj[start[0]])):
        # print("start:{} next:{} vidited:{}".format(start, i, visited))
        if adj[start[0]][i] == 1 and start[1][i] == -1:
            stack.append([i, copy.deepcopy(start[1])])
            # print("append")
            nextNum += 1
            # print("visit to {}".format(next))
            # visited[i] = 1
    if nextNum > 0:
        return nextNum
    elif sum(start[1]) == len(adj):
        return 0
    else:
        return -1


n, m = [int(i) for i in input().split()]
adj = [[0 for j in range(n)] for i in range(n)]  # 隣接行列
for j in range(m):
    a, b = [int(i) - 1 for i in input().split()]
    adj[a][b] = 1
    adj[b][a] = 1

visited = [-1 for i in range(n)]
visited[0] = 1
stack = [[0, visited]]
poped = []
count = 0
while 1:
    size = len(stack)
    # print("\nstack:{}".format(stack))
    if size == 0:
        # print("visited:{}".format(visited))
        break
    next = stack.pop()
    # print("stack:{}".format(stack))
    # if len(stack) != 0:
    # poped.append(next)
    # print("poped:{}".format(poped))
    nextNum = search(next, adj, stack)
    if nextNum == 0:
        count += 1
        # print("ok")
    # elif nextNum == -1:
        # print("missed")
print(count)
