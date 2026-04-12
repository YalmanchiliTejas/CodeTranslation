a,b,c,x,y=map(int,input().split())
ans=[]
if x>=y:
    ans.append(c*2*y+a*(x-y))
else:
    ans.append(c*2*x+b*(y-x))
ans.append(c*2*max(x,y))
ans.append(a*x+b*y)
print(min(ans))
        

