[h,w]=[int(i) for i in input().split()]

li=[]
for i in range(h):
    li.append(list(input()))

p=[]
count=0
for j, i in enumerate(li):
    if "#" not in i:
        p.append(j)
        h-=1
for i in p:
    temp=i-count
    del li[temp]
    count+=1


tli=[]
for i in range(w):
    temp=[]
    for j in li:
        temp.append(j[i])
    tli.append(temp)

count=0
p=[]
for k, i in enumerate(tli):
    if "#" not in i:
        p.append(k)
        w-=1
for i in p:
    temp=i-count
    del tli[temp]
    count+=1

for i in range(h):
    for j in range(w):
        print(tli[j][i], end="")
    print()
