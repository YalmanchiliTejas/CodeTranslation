N=int(input())
SList=[input() for i in range(N)]
SList=[[i for i in S] for S in SList]
MList=[]
M=""
for c in [chr(ord('a') + i) for i in range(26)]:
    _min=min([S.count(c) for S in SList])
    if _min:
        MList.append([c,_min])
for i in MList:
    for n in range(i[1]):
        M+=i[0]
print(M)
