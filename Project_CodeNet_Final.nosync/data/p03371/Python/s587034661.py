A,B,C,X,Y = map(int, input().split())

List=[(A*X)+(B*Y)]

AB=0
AP=0
BP=0
ANS=0
while 1:
    if AP>=X and BP>=Y:
        #print(ANS)
        List.append(ANS)
        break
    if AB==2:
        AP+=1
        BP+=1
        AB=0
    else:
        ANS+=C
        AB+=1

AB=0
AP=X
BP=Y
ANS=0
while 1:
    if AP==0:
        ANS+=(BP*B)
        List.append(ANS)
        break
    elif BP==0:
        ANS+=(AP*A)
        List.append(ANS)
        break
    else:
        if AB==2:
            AP-=1
            BP-=1
            AB=0
        else:
            ANS+=C
            AB+=1
            
#print(List)
print(min(List))
