a,b,c,x,y=map(int,input().split())
ans=2*(max(x,y))*c
temp=0
for i in range(0,2*(max(x,y))+1):#iはABピザの個数。
    if i>=2*x:#いまaピザの個数条件しかかしてないのでこのときbピザが十分存在している時を考慮しないとおかしくなる。
        temp=max(0,(y-(i//2))*b)+i*c
        if temp<=ans:
            ans=temp
    elif i>=2*y:
        temp=max(0,(x-(i//2)))*a+i*c
        if temp<=ans:
            ans=temp
    else:#いまa,bどちらとも不十分の時はまだ場合分けされていない点に留意。
        temp=(x-i//2)*a+(y-i//2)*b+i*c
        if temp<=ans:
            ans=temp
print(ans)