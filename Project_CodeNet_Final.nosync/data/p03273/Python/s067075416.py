H, W = map(int, input().split())

ans = []
# 横白の除去
for h in range(H):
    line = input()
    if "#" in line:
        ans.append(line)


lines = zip(*ans)
ans = []
# 縦白の除去
for line in lines:
    if "#" in line:
        ans.append(line)

an = zip(*ans)

for line in an:
    print(''.join(line))