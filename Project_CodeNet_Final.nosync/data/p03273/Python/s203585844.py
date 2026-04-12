h, w = map(int,input().split())
a = [input() for _ in range(h)]

remove_a = []
for i in range(h):
    if '#' in a[i]:
        remove_a.append(list(a[i]))

n = len(remove_a)
l = []
for i in range(w):
    s = ''
    for j in range(n):
        s += remove_a[j][i]
    if '#' in s:
        l.append(list(s))

ans = ''
for i in range(len(l[0])):
    s = ''
    for j in range(len(l)):
        s += l[j][i]
    ans += s
    if i != len(l[0])-1:
        ans += '\n'
print(ans)