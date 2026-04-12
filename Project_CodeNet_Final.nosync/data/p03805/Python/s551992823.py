n,m = map(int,input().split())
data = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    data[a-1].append(b-1)
    data[b-1].append(a-1)
ans = 0
def search(passed):
    if len(passed)==n:
        global ans
        ans += 1
    else:
        for i in data[passed[-1]]:
            if i in passed:
                continue
            else:
                search(passed+[i])
search([0])
print(ans)