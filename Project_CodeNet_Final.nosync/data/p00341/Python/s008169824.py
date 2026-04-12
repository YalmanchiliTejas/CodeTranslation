e = list(map(int, input().split()))
e.sort()

frag = True
for i in range(1, 4):
    if e[0] != e[i]:
        frag = False
        break
for i in range(5, 8):
    if e[4] != e[i]:
        frag = False
        break
for i in range(9, 12):
    if e[8] != e[i]:
        frag = False
        break

print("yes" if frag else "no")