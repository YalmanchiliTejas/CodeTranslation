n, m = map(int,input().split())
h,w= [],[]
a = [list(input()) for i in range(n)]
b = [i for i in zip(*a)]
for i in range(n):
    if a[i].count(".") == len(a[i]):
        h.append(i)

h = sorted(h,reverse=True)
while h:
    del a[h[0]]
    del h[0]

for i in range(m):
    if b[i].count(".") == len(b[i]):
        w.append(i)

w = sorted(w,reverse=True)
while w:
    for i in range(len(a)):
        del a[i][w[0]]
    del w[0]

for i in range(len(a)):print("".join(a[i]))