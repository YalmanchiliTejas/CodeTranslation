n = int(input())
s = [list(input()) for i in range(n)]
while len(s) > 1:
    a = s.pop(0)
    b = s.pop(0)
    l = []
    for i in a:
        if i in b:
            l.append(i)
            b.remove(i)
    s.insert(0,l)
ans = s.pop(0)
ans.sort()
for i in ans:
    print(i, end = "")