import itertools
n = int(input())
alps = [chr(i) for i in range(97, 97+26)]
ans = {}
for al in alps:
    ans[al] = 10e9
for _ in range(n):
    temp  = input()
    for al in alps:
        co =  temp.count(al)
        if co < ans[al]:
            ans[al] = co
for al in alps:
    if ans[al] != 10e9:
        print(al * ans[al],end="")
