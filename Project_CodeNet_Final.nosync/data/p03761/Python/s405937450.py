import copy
N=int(input())

s=[0]*N

for i in range (N) :
    s[i]=sorted(list(input()))

t=copy.deepcopy(s)
flag=0
ans=[]
i=0
while(len(s[0])>i) :
    for j in range (1,N) :
        if(s[0][i] in s[j]):
            s[j].remove(s[0][i])
        else:
            s=copy.deepcopy(t)
            flag=1
            break
    if(flag==0):
        ans.append(s[0][i])
        s[0].remove(s[0][i])
        i=-1
    t=copy.deepcopy(s)
    flag=0
    i+=1

sorted(ans)
print("".join(ans))