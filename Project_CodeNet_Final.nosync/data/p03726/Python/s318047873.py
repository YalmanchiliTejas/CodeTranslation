import sys
input = sys.stdin.readline

"""
次数1のところにちょっかいを出すことを繰り返す。ダブルリーチが実現できたら勝ち。
"""

N = int(input())
AB = [tuple(int(x)-1 for x in row.split()) for row in sys.stdin.readlines()]

graph = [set() for _ in range(N)]
for a,b in AB:
    graph[a].add(b)
    graph[b].add(a)

deg = [len(x) for x in graph]
deg_1 = set(i for i,x in enumerate(deg) if x == 1)

bl = False
while deg_1:
    x = deg_1.pop()
    y = graph[x].pop()
    graph[y].remove(x)
    for z in graph[y]:
        if z == x:
            continue
        graph[z].remove(y)
        if deg[z] == 1:
            bl = True
            break
        deg[z] -= 1
        if deg[z] == 1:
            deg_1.add(z)
    if bl:break
    graph[y].clear()
    if y in deg_1:
        deg_1.remove(y)

answer = 'First' if bl else 'Second'
print(answer)