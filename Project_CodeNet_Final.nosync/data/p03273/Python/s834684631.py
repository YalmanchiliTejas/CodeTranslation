#abc107  b
h,w=map(int,input().split())
a=[]
gyo=[False]*h
for i in range(h):
    line=input()
    a.append(line)
    if line.count(".")==w:
        gyo[i]=True
retsu=[False]*w
for i in range(w):
    cnt=0
    for j in range(h):
        if a[j][i]==".":
            cnt+=1
    if cnt==h:
        retsu[i]=True

#print(gyo,retsu)
for i in range(h):
    if gyo[i]==False:
        line=""
        for j in range(w):
            if retsu[j]:
                continue
            else:
                line+=a[i][j]
        print(line)
