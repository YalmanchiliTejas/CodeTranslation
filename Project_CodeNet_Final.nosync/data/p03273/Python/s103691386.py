inputs = input().strip().split()

H = int(inputs[0])
W = int(inputs[1])

a = []

for i in range(H):
    inputs = input()
    a.append(inputs)

for i in range(W):
    flag = True
    for j in range(H):
        if a[j][i] == "#":
            flag = False
    if flag:
        for j in range(H):
            a[j] = a[j][:i] + '*' + a[j][i+1:]

for i in range(H):
    if a[i].find("#") < 0:
        a[i] = ''

for i in range(H):
    if a[i] != '':
        print(a[i].replace('*', ''))