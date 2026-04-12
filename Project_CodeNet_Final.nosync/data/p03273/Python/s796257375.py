H,W=map(int,input().split())

list1=[]
for i in range(H):
    a=input()
    if a.count(".")==len(a):
        pass
    else:
        list2=[]
        for m in range(len(a)):
            
            list2.append(a[m])
        list1.append(list2)
        list2=[]
#print(list1[0][3])
list3=[]
for j in range(W):
    count=0
    if list1[0][j]==".":
        for k in range(len(list1)):
            if list1[k][j]==".":
                count+=1
        if count==len(list1):
            list3.append(j)
            
#print(list3)

list4=[]
for x in range(len(list1)):
    list5=[]
    for y in range(W):
        if y in list3:
            pass
        else:
            list5.append(list1[x][y])
    list4.append(list5)
    list5=[]
#print(list4)

for c in range(len(list4)):
    print("".join(list4[c]))