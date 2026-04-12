h,w = map(int,input().split())
a = []
for _ in range(h):
    i = input()
    if "#" in i:
        a.append(i)

ans = []
for i in zip(*a):
    if "#" in i:
        ans.append(i)
for j in zip(*ans):
    print(*j,sep = "")