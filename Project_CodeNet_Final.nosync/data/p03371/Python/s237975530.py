a,b,c,x,y=map(int,input().split())
m=float('inf')
for i in range(10**5+1):
    m=min(m,i*2*c+max(0,x-i)*a+max(0,y-i)*b)
print(m)
