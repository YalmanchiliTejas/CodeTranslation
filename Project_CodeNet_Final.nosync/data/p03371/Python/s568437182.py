a,b,c,x,y=map(int,input().split())

cnt=10**9
for m in range(max(x,y)+1):
    price=(2*m*c)+max(0,(x-m))*a+max(0,y-m)*b
    cnt=min(cnt,price)
    
print(cnt)