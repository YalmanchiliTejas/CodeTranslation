n, x, m = map(int, input().split())
li = [x]
seen = [False]*m
seen[x] = True
for i in range(n-1):
    x = x*x%m
    if seen[x]:
        idx = li.index(x)
        break
    seen[x] = True
    li.append(x)
else:
    print(sum(li))
    exit(0)
ans = sum(li) + sum(li[idx:])*((n-len(li)) // (len(li)-idx)) + sum(li[idx:idx+(n-len(li)) % (len(li)-idx)])
print(ans)