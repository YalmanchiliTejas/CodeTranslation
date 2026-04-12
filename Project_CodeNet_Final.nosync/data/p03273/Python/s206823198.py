h,w = [int(i) for i in input().split()]

m = []
l = [False for i in range(w)]

for i in range(h):
    s = input()
    flg = False
    if '#' in s:
        m.append(s)
    for j in range(w):
        if l[j]==False and s[j] == '#':
            l[j] = True
for i in m:
    for j in range(w):
        if l[j]:
            print(i[j],end='')
    print()
