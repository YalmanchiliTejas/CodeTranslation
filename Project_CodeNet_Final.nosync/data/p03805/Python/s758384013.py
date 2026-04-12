from collections import defaultdict
vertices, edges = map(int, input().split(" "))
connect = defaultdict(set)
for e in range(edges):
    a, b = map(lambda n:n - 1, map(int, input().split(" ")))
    connect[a] |= {b}
    connect[b] |= {a}
queue = [[0, set()]]
answer = 0
while queue:
    next_queue = []
    # print(queue)
    for q in queue:
        here, visited = q
        new_visited = set()
        new_visited |= visited | {here}
        if len(new_visited) == vertices:
            # print(new_visited, here, queue)
            answer += 1
        for conn in connect[here]:
            if conn not in new_visited:
                next_queue.append([conn, new_visited])
    queue = next_queue
print(answer)