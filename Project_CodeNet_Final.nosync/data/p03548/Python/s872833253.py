x,y,z=[int(i) for i in input().split()]
x-=z*2
ans=0
while y+z<=x:
        x-=(y+z)
        ans+=1
        #print(x)
if y<=x:
        ans+=1
        #print(x)
print(ans)