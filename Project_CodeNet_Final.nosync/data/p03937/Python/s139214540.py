H,W = map(int,input().split())
num = 0
for i in range(H):
    a = input()
    if "#" in a[:num]:
        print("Impossible")
        exit()
    cnt = -1
    for j in range(num, W):
        if a[j] == "#":
            cnt += 1
        else:break
    num += cnt
    if "#" in a[num+1:]:
        print("Impossible")
        exit()
print("Possible")