a,b,c,x,y = map(int,input().split())
cost = 0
mincost = 100000*5000*10

for i in range(0,max(x,y)+1):
    cost = a*max(x-i,0)+b*max(y-i,0)+c*(2*i)
    mincost = min(cost,mincost)
    
print(mincost)