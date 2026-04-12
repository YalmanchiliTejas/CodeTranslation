n = int(input())
S = []
for _ in range(n):
    S += [list(input())]

t = list('abcdefghijklmnopqrstuvwxyz')
count = []
x = 0
for i in t:
    x += 1
    # print (i, x)
    tmp = 50
    for j in S:
        tmp = min(tmp, j.count(i))
    count += [tmp]
# print (count)
for k in range(26):
    for l in range(count[k]):
        print (t[k], end = '')

print ()
