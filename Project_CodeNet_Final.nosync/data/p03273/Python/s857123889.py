h,w = map(int,input().split())
a = list()
for i in range(h):
    s = input()
    if s != '.'*w:
        a.append(s)
n = len(a)
k = 0
while k < w:
    if all(a[i][k] == '.' for i in range(n)):
        for j in range(n):
            a[j] = a[j][:k] + a[j][k+1:]
        w -= 1
    else:
        k += 1
for i in range(n):
    print(a[i])