n,m = map(int,input().split(' '))

bar = [[] for _ in range(n)]

for i in range(m):
    a,b = map(lambda x:int(x)-1,input().split(' '))
    bar[a].append(b)
    bar[b].append(a)

result = 0

def search(root=[0]):
    global result
    if len(root) >= n:
        result += 1
        return
    nxt = set(bar[root[-1]])
    nxt = nxt - set(root)
    for nxt_ in nxt:
        search(root+[nxt_])

search()
print(result)