a,b,c,x,y=map(int,input().split())
ans=a*x+b*y
l=[ans]
for i in range(min(x,y)):
    ans=ans-a-b+c+c
    l.append(ans)
l.append(2*c*max(x,y))
print(min(l))