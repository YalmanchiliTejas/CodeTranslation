h, w = map(int, input().split())
f = [list(input()) for i in range(h)]

i = w-1
while i >= 0:
    col = ""
    for j in range(h):
        col += f[j][i]
    if col == "."*h:
        for j in range(h):
            del f[j][i]
    i -= 1

i = h-1
while i >= 0:
    if set(f[i]) == {"."}: del f[i];
    i -= 1

for i in f:
    print("".join(i))