h, w = map(int, input().split())
a = input()
box = []
for i in range(w):
    if a[i] == ".":
        box.append(i)

if "#" in a:
    pages = [a]
else:
    pages = []

for i in range(h-1):
    a = input()
    if "#" in a:
        pages.append(a)
    else:
        continue
    for j in box:
        if a[j] != ".":
            box.remove(j)

box.reverse()
for i in range(len(pages)):
    for j in box:
        pages[i] = pages[i][:j] + pages[i][j+1:]

    print(pages[i])
