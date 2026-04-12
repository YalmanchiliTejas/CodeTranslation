x,y,z=map(int,input().split())
for i in range(1,100001):
    if i*y+(i+1)*z>x:
        key=i-1
        break
        
print(key)