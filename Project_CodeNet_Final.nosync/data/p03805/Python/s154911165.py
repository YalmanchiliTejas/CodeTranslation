import itertools

n, m = map(int,input().split())
edges = [list(map(int,input().split())) for _ in range(m)]

node = [i for i in range(2,n+1)]
permutations_node = itertools.permutations(node)
ans = 0

for one_node in permutations_node:
    start = 1
    memo = []
    for x in one_node:
        for edge_x, edge_y in edges:
            if edge_x == start and edge_y == x and x not in memo:
                memo.append(x)
                start = x
            if edge_x == x and edge_y == start and x not in memo:
                memo.append(x)
                start = x
                
    if len(memo) == n-1:
        ans += 1
    
print(ans)