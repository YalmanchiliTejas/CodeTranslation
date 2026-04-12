h,w = map(int, input().split(" "))
string = [input() for i in range(h)]

a = [i for i in range(h)]
for i in range(h):
    if string[i] == "."*w:
        a.remove(i)

stringT = [[string[j][i] for j in range(h)] for i in range(w)]

b = [i for i in range(w)]

for i in range(w):
    if "".join(stringT[i]) == "."*h:
        b.remove(i)

st = [[string[i][j] for j in b] for i in a]
for i in range(len(st)):
    print("".join(st[i]))