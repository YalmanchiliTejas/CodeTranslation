H, W = map(int, input().split())
a = ['' for _ in range(W)]
white = ['.' for _ in range(W)]
white = ''.join(white)

h = 0
for i in range(H):
    inp = input()
    if inp == white:
        continue
    for j, c in enumerate(inp):
        a[j]+=c
    h+=1

b = ['' for _ in range(h)]
white = ['.' for _ in range(h)]
white = ''.join(white)

for i in range(W):
    inp = a[i]
    if inp == white:
        continue
    for j, c in enumerate(inp):
        b[j]+=c

for i in range(h):
    print(b[i])