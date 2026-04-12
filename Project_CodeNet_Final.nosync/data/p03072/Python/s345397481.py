N  = input()
Hs = list(map(int,input().split(" ")))
limit = len(Hs)
ans = 0
for i in range(limit):
    h = Hs[i]
    flag = True
    for another in Hs[:i]:
        if h < another:
            flag = False
    if flag:
        ans += 1
print(ans)