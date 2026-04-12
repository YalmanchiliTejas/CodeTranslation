import itertools
n, m = map(int, input().split())
ab = []
for i in range(m):
    ab.append(list(map(int, input().split())))
per = list(itertools.permutations([i+1 for i in range(n)]))
ans = 0
for i in range(len(per)//n):
    # print(per[i])
    flug = True
    for j in range(n-1):
        way = list(per[i][j:j+2])
        # print(way, way[::-1], ab)
        if not((way in ab) or (way[::-1] in ab)):
            flug = False
            break
    if flug:
        ans += 1
print(ans)