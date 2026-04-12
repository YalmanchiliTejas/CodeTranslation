n=int(input())

biglist1=[]
biglist2=[]

for i in range(n):
    nlist=[]
    nlist2=[]
    s=input()
    s=sorted(s)
    ln=len(s)
    before='0'
    for j in range(ln):
        if s[j]==before:
            nlist[-1][1]+=1
        else:
            nlist.append([s[j],1])
            nlist2.append(s[j])
        before=s[j]
    biglist1.append(nlist)
    biglist2.append(nlist2)

#print(biglist1)
#print(biglist2)
answer=""
for i in range(len(biglist1[0])):
    kaz=biglist1[0][i][1]
    for j in range(len(biglist1)):
        #print(biglist2[j], biglist2[0][i])
        #print(biglist2[j].index(biglist2[0][i]))
        if biglist2[0][i] in biglist2[j]:
            list3=biglist2[j]
            moji=biglist2[0][i]
            result=list3.index(moji)
            kaz=min(kaz, biglist1[j][result][1])
            pass
        else:
            kaz=0
    #print(kaz)
    answer+=biglist2[0][i]*kaz
print(answer)