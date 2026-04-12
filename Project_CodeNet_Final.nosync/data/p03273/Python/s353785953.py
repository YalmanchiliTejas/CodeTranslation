#n = int(input())
#n,k = map(int,input().split())
#x = list(map(int,input().split()))



h,w = map(int,input().split())
a = [(list(input())) for _ in range(h)]

ans1 = []
ans2 = [[0 for _ in range(w)] for _ in range(h)]

for i in range(h):
    if not("#" in a[i]):
        continue
    else:
        ans1.append(a[i])

cnt = 0
for i in range(w):
    bre = True
    for j in range(len(ans1)):
        if ans1[j][i] == "#":
            bre = False
    if not(bre):
        for k in range(len(ans1)):
            ans2[k][cnt] =  ans1[k][i]
        cnt += 1

for i in range(h):
    for j in range(w):
        if ans2[i][j] != 0:
            print(ans2[i][j],end="")
    print()





