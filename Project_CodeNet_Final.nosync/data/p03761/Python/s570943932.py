n = int(input())

a = 'abcdefghijklmnopqrstuvwxyz'
d = []
for i in range(n):
    tmp = dict()
    for c in a:
        tmp[c] = 0
    d.append(tmp)

for i in range(n):
    s = input()
    for c in s:
        d[i][c]+=1

res = ""
for c in a:
    res += c*min([d[i][c] for i in range(n)])
print(res)


