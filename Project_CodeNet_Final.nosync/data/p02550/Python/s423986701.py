n, x, m = map(int, input().split())
li = [x]
se = {x}
for i in range(n-1):
    x = x*x%m
    if x in se:
        idx = li.index(x)
        break
    li.append(x)
    se.add(x)
else:
    print(sum(li))
    exit(0)
ans = sum(li) + sum(li[idx:])*((n-len(li)) // (len(li)-idx)) + sum(li[idx:idx+(n-len(li)) % (len(li)-idx)])
print(ans)