H , W =map(int, input().split())
a = []
for i in range(H):
    s = input()
    if '#' in s:
        a.append(s)

new_a =[]

for i in range(W):
    for j in range(len(a)):
        if a[j][i] == '#':
            s = ""
            for k in range(len(a)):
                s += a[k][i]
            new_a.append(s)
            break

for i in range(len(new_a[0])):
    s = ""
    for j in range(len(new_a)):
        s += new_a[j][i]
    print(s)
