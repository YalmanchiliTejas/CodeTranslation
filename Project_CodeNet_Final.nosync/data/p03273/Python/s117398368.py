i,j=map(int,input().split())
li=[]
for s in range(i):
    p=str(input())
    li.append(p)
def provre(x):
    lll=0
    br=0
    for z in range(len(x)):
        if x[z]=='.':
            br+=1
    if br==len(x):
        lll=1
    return(lll)
li2=[]
for a in range(len(li)):
    if provre(li[a])==0:
        li2.append(li[a])
li=li2

def prost(x):
    sd=[]
    L = [1] * len(x[0])
    for i in range(len(x[0])):
        ooo=1
        cnt = 0
        for s in range(len(x)):
            if x[s][i]=='.':
                cnt += 1
        if cnt == len(x):
            ooo = 0
        if ooo==0:
            L[i] = 0
              
    for j in range(len(x)):
        s = ""
        for q in range(len(x[0])):
            if L[q]==1:
                s+=x[j][q]
        sd.append(s)
    for ka in range(len(sd)):
        print(sd[ka])


prost(li)