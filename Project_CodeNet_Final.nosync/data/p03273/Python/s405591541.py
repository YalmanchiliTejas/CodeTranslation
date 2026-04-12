h,w = list(map(int,input().split()))

x = []
for i in range(h):
    x.append(input())

x2  = []
for i in x:
    if '#' in i:
        x2.append(i)

de = []

for i in range(w):
    flag = 0
    for line in x2:
        if line[i] == '#':
            flag = 1
            break
    if flag == 0:
        de.append(i)

for line in x2:
    st = ""
    for i in range(w):
        if i in de:
            pass
        else:
            st += line[i]
    print(st)
