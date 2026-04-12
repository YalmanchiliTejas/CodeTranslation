h, w = map(int, input().split())
s = []
s0 = []
for i in range(h):
    s.append(input())

for i in range(h):
    if s[i].count('#') != 0:
        s0.append(s[i])

s1 = [list(a) for a in s0]
# print(s1)
for i in range(len(s1[0])):
    for j in range(len(s1)):
        if s1[j][i] == '#':
            break
        elif j == len(s1) - 1:
            for k in range(len(s1)):
                s1[k][i] = 0
        else:
            continue
for r in s1:
    for c in r:
        if c != 0:
            print(c, end='')
    print()