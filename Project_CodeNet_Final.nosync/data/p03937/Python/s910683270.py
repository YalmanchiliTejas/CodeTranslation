h,w=map(int,input().split())
data=[]
for i in range(h):
    a=input()
    data.append(a)
ans="Possible"
r=0
for i in range(h):
    for j in range(w):
        if data[i][j]=="#":
            if j<r:
                ans="Impossible"
                break
            else:
                r=j
    if ans=="Impossible":
        break
print(ans)