x,y,z=map(int,input().split())
cnt=0
x-=z
while x>=0:
    x=x-(y+z)
    if x>=0:
        cnt+=1
    else:
        break
        
print(cnt)