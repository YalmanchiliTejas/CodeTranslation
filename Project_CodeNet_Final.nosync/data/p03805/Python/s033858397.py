n, m = map(int, input().split())
road = [[] for _ in range(n)]
result = [0] * n
def search(loc):
    result[loc] = 1
    if sum(result) == n:
        result[loc] = 0
        return 1
    
    cnt = 0
    for r in road[loc]:
        if result[r] == 0:
            cnt += search(r)
    result[loc] = 0
    return cnt
    

for _ in range(m):
    a, b = map(int,input().split())
    road[a-1].append(b-1)
    road[b-1].append(a-1)
print(search(0))
