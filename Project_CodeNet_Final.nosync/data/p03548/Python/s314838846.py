x,y,z=map(int,input().split())
num=0
sum=z
for i in range(x) :
    if sum<=x :
        sum+=y
        num+=1
        sum+=z
print(num-1)
