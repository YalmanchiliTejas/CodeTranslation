H,W = map(int,input().split())

L = [list(input()) for i in range(H)]

cnt = 0
for i in L:
    c = i.count("#")
    cnt += c

if cnt == H + W - 1:
    print("Possible")
else:
    print("Impossible")