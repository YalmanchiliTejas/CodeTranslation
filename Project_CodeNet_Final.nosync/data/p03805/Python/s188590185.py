n, m = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(m)]
visited = [False]*n
counter =0

def v_list(value, vector):
    result = []
    for i in range(len(vector)):
        if value in vector[i]:
            result.append(vector[i][0])
            result.append(vector[i][1])
    while value in result:
        result.remove(value)
    return result


def DFS(x):
    next_x = v_list(x, c)
    all_visited = True
    for i in range(n):
        if not visited[i]:
            all_visited = False

    if all_visited:
        global counter
        counter +=1
        return

    for i in next_x:
        if not visited[i-1]:
            visited[i-1] = True
            DFS(i)
            visited[i-1] = False

visited[0] = True
DFS(1)
print(counter)