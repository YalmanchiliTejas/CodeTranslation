h,w=map(int,input().split())
list1=[]
ans=0
count1=0
count2=0
count3=0
for i in range(h):
    list1.append(list(input()))
for i in range(h):
    count3+=list1[i].count("#")
if count3!=h+w-1:
    ans=1
for i in range(h+w-3):
    if count2!=w-1:
        if list1[count1][count2+1]=="#":
            count2+=1
    if count1!=h-1:
        if list1[count1+1][count2]=="#":
            count1+=1
    if count2!=w-1:
        if count1!=h-1:
            if list1[count1+1][count2]=="." and list1[count1][count2+1]==".":
                ans=1
                break
        else:
            if list1[count1][count2+1]==".":
                ans=1
                break
    elif count1!=h-1:
        if list1[count1+1][count2]==".":
            ans=1
            break
if count1!=h-1 or count2!=w-1:
    ans=1
if h==2 and w==2:
    if list1[0][0]=="#" and list1[1][1]=="#" and count3==3:
        ans=0
if ans==1:
    print("Impossible")
else:
    print("Possible")
