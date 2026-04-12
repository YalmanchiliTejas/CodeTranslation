n,m = map(int, input().split())
tree = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

def search(now, hist,cnt):
    for i in tree[now]:
        if i in hist:
            pass
        else:
            cnt = search(i, hist+[i],cnt)
    if len(hist)==n: #found
        return cnt + 1
    else: #not found
        return cnt
print(search(1,[1],0))