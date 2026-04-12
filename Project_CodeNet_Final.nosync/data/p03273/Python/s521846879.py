h,w = map(int,input().split())
ls = [list(input()) for _ in range(h)]
num = []
di = [0]*w
for i in range(h):
    if "#" not in ls[i]:
        num.append(i)
    for j in range(w):
        if ls[i][j] == "#":
            di[j] += 1
num = sorted(num,reverse=True)
for k in range(h-1,-1,-1):
    if k in num:
        ls.pop(k)
        continue
    for l in range(w-1,-1,-1):
        if di[l] == 0:
            ls[k] = ls[k][:l] + ls[k][l+1:]
for p in range(h-len(num)):
    print("".join(ls[p]))

