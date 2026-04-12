n = int(input())
s = input()
k = int(input()) -1
d = s[k]
w = []
for i in range(n):
    if s[i] != d:
        w.append('*')
    else:
        w.append(d)
print(*w, sep='')