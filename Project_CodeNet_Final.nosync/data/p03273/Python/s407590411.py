h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
memo_yoko = []
memo_tate = []
for i in range(h):
    if "#" in a[i]:
        memo_yoko.append(i)

for j in range(w):
    if any(a[i][j] == "#" for i in range(h)):
        memo_tate.append(j)
#print(memo_yoko)
#rint(memo_tate)
for i in memo_yoko:
    for j in memo_tate:
        print(a[i][j], end="")
    print()