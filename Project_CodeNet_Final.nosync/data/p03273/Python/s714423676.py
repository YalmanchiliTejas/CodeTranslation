h,w = map(int, input().split())
index1=0
listForList = []
while index1<h:
    list1 = list(input())
    if "#" in list1:
        listForList.append(list1)
    index1+=1

listForIndex=[]
index2 =0
while index2<w:
    index3=0
    flag =0
    while index3<len(listForList):
        if listForList[index3][index2]=="#":
            flag=1
        index3+=1
    if flag==0:
        listForIndex.append(index2)
    index2+=1

if len(listForIndex)>0:
    for index4 in listForIndex:
        index5=0
        while index5<len(listForList):
            listForList[index5][index4] = ""
            index5+=1

for list2 in listForList:
    print("".join(list2))