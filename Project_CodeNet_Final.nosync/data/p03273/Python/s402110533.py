H, W = map(int, input().split())
lines = []
linesT = []
count = 0

for i in range(H):
    line = input()
    if line.count('.') == W:
        H -= 1
        continue
    else:
        lines.append(line)

for i in range(W):
    string =''
    for j in range(H):
        string += lines[j][i]
    linesT.append(string)

lines = []
for i in range(W):
    if linesT[i].count('.') == H:
        W -= 1
        continue
    else:
        lines.append(linesT[i])

ans = []
for i in range(H):
    string = ''
    for j in range(W):
        string += lines[j][i]
    ans.append(string)

for i in range(len(ans)):
    print(ans[i])