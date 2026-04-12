# 631

h, w = map(int, input().split())
a = [str(input()) for _ in range(h)]
jud = [[] for _ in range(h)]

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            jud[i].append(j)

# print(jud)

flag = True

for k in range(len(jud) - 1):
    if max(jud[k]) in jud[k + 1] and jud[k][-1] == jud[k + 1][0]:
        continue
    else:
        flag = False

if flag:
    print("Possible")
else:
    print('Impossible')