h,w = map(int,input().split())
array = []
for _ in range(h):
    temp = input()
    if temp.count(".")==w:
        h-=1
        continue
    array.append(temp)

skip = [i for i in range(w)]

for j in range(w):
    flag=0
    for i in range(h):
        if array[i][j]=="#":
            flag=1
            break
    if flag==0:
        skip.remove(j)

for i in range(h):
    for j in skip:
        print(array[i][j], end="")
    print()