#shink and stone
h,w=map(int,input().split())
flag=True
dif=[]
for i in range(h):
    s=input()
    lists=[]
    for i in range(w):
        if s[i]=="#":
            lists.append(i+1)
    for i in range(len(lists)-1):
        if lists[i+1]-lists[i]>1:
            flag=False
            break
    dif.append((lists[0],lists[-1]))
if flag:
    subflag=True
    for i in range(h-1):
        if dif[i+1][0]!=dif[i][1]:
            subflag=False
            break
    if subflag:
        print("Possible")
    else:
        print("Impossible")
else:
    print("Impossible")