h,w=map(int,input().split())
point=[0]*w
a=[]
for _ in range(h):
    x=input()
    if x.count("#")!=0:
        a.append(x)
        for i in range(w):
            if x[i]=="#":
                point[i]+=1
for k in range(len(a)):
    s=a[k]
    ans=""
    for j in range(w):
        if point[j]!=0:
            ans+=s[j]
    print(ans)
