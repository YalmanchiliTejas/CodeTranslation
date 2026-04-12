h, w = input().split()
h = int(h)
w = int(w)
lines = list()
c = [0]*w
for _ in range(h):
    line = input()
    if line=="."*w:
        continue
    lines.append(line)
    for i in range(w):
        if line[i]==".":
            c[i] += 1
h = len(lines)
ans = list()
for j in range(h):
    line = ""
    for i in range(w):
        if c[i] != h:
            line += lines[j][i]
    ans.append(line)
print("\n".join(ans))