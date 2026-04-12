a,b,c,x,y=map(int,input().split())
m=10**10
for i in range(10**6):
    m=min(m,2*c*i+a*max(0,x-i)+b*max(0,y-i))
print(m)