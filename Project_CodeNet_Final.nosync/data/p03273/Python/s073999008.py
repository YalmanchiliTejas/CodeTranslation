H,W = map(int,input().split())
a = [list(input()) for i in range(H)]

ans = []
for i in a:
    if "#" in i:
        ans.append(i)

ans_T = list(zip(*ans))
ans = []

for i in ans_T:
    if "#" in i:
        ans.append(i)

ans = list(zip(*ans))

for i in ans:
    print("".join(i))
