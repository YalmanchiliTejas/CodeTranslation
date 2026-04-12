h, w = map(int, input().split())
a = []
for i in range(h):
    wi = input()
    if wi != "."*w:
        a.append(wi)
b = []
for j in range(w):
    wi2 = ""
    for i in range(len(a)):
        wi2 += a[i][w-j-1]
    if wi2 != "."*len(a):
        b.append(wi2)
ans = []
for i in range(len(b[0])):
    hi3 = ""
    for j in range(len(b)):
        hi3 += b[len(b)-j-1][i]
    print(hi3)
