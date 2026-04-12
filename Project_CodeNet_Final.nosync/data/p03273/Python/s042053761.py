h,w=map(int,input().split())
list=[]
for i in range(h):
    a=input()
    if "#" in a:
        list.append(a)
h=len(list)
d=[0]*w
for i in range(h):
    for j in range(w):
        if list[i][j]=="#":
            d[j]=1
for i in range(h):
    ans=""
    for j in range(w):
        ans+=list[i][j]*d[j]
    print(ans)