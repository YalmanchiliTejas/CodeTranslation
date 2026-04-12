n = int(input())
alp = 'abcdefghijklmnopqrstuvwxyz'
z = []
for i in range(n):
    s = input()
    t = []
    for i in range(26):
        t.append(s.count(alp[i]))
    z.append(t)


x = ''
for i in range(26):
    cnt = min([j[i] for j in z])
    x += alp[i]*cnt
print(x)
