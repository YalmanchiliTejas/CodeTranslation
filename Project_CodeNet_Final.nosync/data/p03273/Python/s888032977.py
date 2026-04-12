h, w = [int(i) for i in input().split()]

a = []

for i in range(h):
    str_list = input()
    a_list = [0 if j == "." else 1 for j in str_list]
    a.append(a_list)

i = 0
while i < h:
    if i > len(a)-1:
        break
    if sum(a[i]) == 0:
        a.pop(i)
        i-=1
    i+=1


i = 0
while i < w:
    if i > len(a[0])-1:
        break
    if sum([a[j][i] for j in range(len(a))]) == 0:
        for j in range(len(a)):
            a[j].pop(i)
        i-=1
    i+=1


for i in range(len(a)):
    outlist = ["." if a[i][j] == 0 else "#" for j in range(len(a[0]))]
    str_list = ""
    for j in outlist:
        str_list+=j
    print(str_list)
