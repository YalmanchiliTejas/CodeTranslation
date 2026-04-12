h,w = map(int,input().split())
li,li2 = [],[]
for i in range(h):
    a = list(input())
    if "#" in a:
        li.append(a)
for i in range(len(li)):
    for j in range(w):
        if li[i][j] == ".":
            li[i][j] = 0
        elif li[i][j] == "#":
            li[i][j] = 1

li = list(zip(*li))
for i in range(len(li)):
    if 1 in li[i]:
        li2.append(li[i])
li2 = list(zip(*li2))
for i in range(len(li2)):
    li2[i] = list(li2[i])
for i in range(len(li2)):
    for j in range(len(li2[i])):
        if li2[i][j] == 0:
            li2[i][j] = "."
        elif li2[i][j] == 1:
            li2[i][j] = "#"
for i in range(len(li2)):
    print("".join(li2[i]))