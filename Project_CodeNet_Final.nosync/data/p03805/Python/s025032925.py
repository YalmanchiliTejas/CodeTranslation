import copy
n, m = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(m)]
cnt = 0
fin = set([i + 1 for i in range(n)])
def path(now, edges, past):
    global cnt
    if set(past) == fin:
        cnt += 1
        return 0
    for i in range(len(edges)):
        if now == edges[i][0] and edges[i][1] not in past:
            new_now = edges[i][1]
            new_edges = copy.deepcopy(edges)
            new_past = copy.deepcopy(past)
            new_edges.pop(i)
            new_past.append(edges[i][1])
            # print("now", now, "edges", edges, "new", new_edges, "past", past, "cnt", cnt)
            path(new_now, new_edges, new_past)
        elif now == edges[i][1] and edges[i][0] not in past:
            new_now = edges[i][0]
            new_edges = copy.deepcopy(edges)
            new_past = copy.deepcopy(past)
            new_edges.pop(i)
            new_past.append(edges[i][0])
            # print("now", now, "edges", edges, "new", new_edges, "past", past, "cnt", cnt)
            path(new_now, new_edges, new_past)

for i in range(m):
    if ab[i][0] == 1:
        edges = copy.deepcopy(ab)
        edges.pop(i)
        path(ab[i][1], edges, [1, ab[i][1]])
    elif ab[i][1] == 1:
        edges = copy.deepcopy(ab)
        edges.pop(i)
        path(ab[i][0], edges, [1, ab[i][0]])
print(cnt)
