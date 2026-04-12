from collections import defaultdict

N, M = map(int, input().split())
adj_list = defaultdict(set)

for i in range(M):
    a, b = map(int, input().split())
    adj_list[a].add(b)
    adj_list[b].add(a)

visited = set() # 隣接ノードが1つだけになるノードを順々に追加

res = 0

def backtrack(visited, num):
    global res
    if num in visited:
        return
    if len(visited | {num}) == N:
        res = res + 1
        return

    for neighbor in adj_list[num]:
        backtrack(visited | {num}, neighbor)

backtrack(visited, 1)

print(res)