n,x,m=map(int,input().split())

col=[x]
sude=[0]*m
sude[x]=1
now=x
ishu=0
hajimari=0
for i in range(m):
    now**=2
    now%=m
    #print(now)
    if(sude[now]==0):
        sude[now]=i+2
        col.append(now)
    else:
        ishu=i-sude[now]+2
        hajimari=sude[now]-1
        break


#print(ishu,hajimari,col)

saisho=0
loop=0
for i in range(hajimari):
    saisho+=col[i]
for i in range(hajimari,len(col)):
    loop+=col[i]

#print(saisho,loop)

ans=0

if(n<hajimari):
    ans+=col[i]
else:
    ans=saisho+loop*((n-hajimari)//ishu)
    nokori=n-hajimari-ishu*((n-hajimari)//ishu)
    for i in range(hajimari,hajimari+nokori):
        ans+=col[i]

print(ans)