import math

H,W=(int(i) for i in input().split())
li=[]
for i in range(0,H):
    li2=[]
    S1=input()
    for j in range(0,W):
        li2.append(S1[j])
        #print(li2)

    li.append(li2)
    
#print(li)
Flag=False
#横探索
for i in range(0,H):
    
    for j in range(0,W):
        if (li[i][j]=="." or li[i][j]=="Remove"):
            Flag=True
        else:
            Flag=False
            break

    if Flag==True:
         for j in range(0,W):
            li[i][j]="Remove"
          


    
#横探索
for i in range(0,W):
    
    for j in range(0,H):
         if (li[j][i]=="." or li[j][i]=="Remove"):
            Flag=True
         else:
            Flag=False
            break

    if Flag==True:
         for j in range(0,H):
            li[j][i]="Remove"
       
for i in range(0,H):
    for j in range(0,W):
        if (li[i][j]=="Remove"):
            li[i][j]=""

#print("ans")
for i in range(0,H):
    count=0
    for j in range(0,W):
        
        if (li[i][j]==""):
            Flag=True
            count+=1
        else:
            Flag=False
        
        print(str(li[i][j]),end="")

    if count!=W:
        print("")   


    
    
