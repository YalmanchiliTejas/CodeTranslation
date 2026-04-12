a,b,c,x,y = map(int,input().split())
anlist=[]
for i in range(max(x,y)+1):
    ans = 2*c*i+a*max(0,x-i)+b*max(0,y-i)
    anlist.append(ans)
print(min(anlist))