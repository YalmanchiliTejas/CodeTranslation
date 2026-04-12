x,y,z=map(int,input().split())
temp=x-z
count=0
flag=0
while(flag==0):
    if temp-(y+z)>=0:
        temp=temp-(y+z)
        count+=1
    else:
        flag+=1
print(count)







