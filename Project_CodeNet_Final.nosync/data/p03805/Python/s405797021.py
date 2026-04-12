def DFS(Current_Node,Visited_Node):
    if len(Visited_Node) == N - 1:
        return 1
    ans = 0

    for a,b in AB:
        if a == Current_Node and b not in Visited_Node:
            vns = Visited_Node.copy()
            vns.add(a)
            ans += DFS(b, vns)

        if b == Current_Node and a not in Visited_Node:
            vns = Visited_Node.copy()
            vns.add(b)
            ans += DFS(a,vns)
    return ans



N,M = map(int,input().split())
AB = []

for i in range(M):
    a,b = map(int,input().split())
    AB.append((a,b))

ans = DFS(1,set())
print(ans)
