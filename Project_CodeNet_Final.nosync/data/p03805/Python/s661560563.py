n, m = map(int, input().split())
Adj_dict = {}
for i in range(n):
    new = {i:[]}
    Adj_dict.update(new)
for _ in range(m):
    a, b = map(int, input().split())
    Adj_dict[a-1].append(b-1)
    Adj_dict[b-1].append(a-1)

Visit_list = [True] + [False for _ in range(n-1)]
count = 0

def Path(dict, start, Visited):

    if all(Visited):
        global count
        count += 1
        return

    for node in dict[start]:
        if Visited[node] == False:
            Visited[node] = True
            Path(dict, node, Visited)
            Visited[node] = False
    return

Path(Adj_dict, 0, Visit_list)
print(count)