h,w= map(int, input().split())
s = []
a = []
for i in range(h):
    temp = input()
    if '#' in temp:
        s.append(temp)
for j in range(w):
    flag = False
    for i in s:
        if i[j] == '#':
            flag = True
            break
    a.append(flag)
s = ["".join(j[i] for i in range(w) if a[i]) for j in s]
 
for x in s:
    print(x)