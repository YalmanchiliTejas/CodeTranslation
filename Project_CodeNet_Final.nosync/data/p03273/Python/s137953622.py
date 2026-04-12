H, W = map(int,input().split())

pic = []
for i in range(H):
    a = list(input())
    if a != ["." for i in range(W)]:
        pic.append(a)

H = len(pic)
        
delete = [0 for i in range(W)]
for i in range(W):
    white = 0
    for j in range(H):
        if pic[j][i] == ".":
            white += 1
        if white == H:
            delete[i] += 1

for i in reversed(range(W)):
    if delete[i] == 1:
        for j in range(H):
            pic[j] = pic[j][0:i] + pic[j][i+1:]

for i in range(H):
    print(*pic[i], sep="")
