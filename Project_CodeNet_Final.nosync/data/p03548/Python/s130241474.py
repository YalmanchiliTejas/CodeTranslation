x,y,z=map(int,input().split())
count=0
while x>=y+2*z:
    x=x-y-z
    count+=1
print(count)    
