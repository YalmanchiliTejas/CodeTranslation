N=int(input())
kekka=list(input().split())
#print(kekka)
base=kekka[0]
#result=0
for i in range(1,N):
    if base=="F":
        base="T"
        #print(1)
    elif base=="T":
        if kekka[i]=="T":
            base="T"
            #print(2)
        else:
            base="F"
            #print(3)
            
print(base)
        
