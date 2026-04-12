x,y,z=map(int,input().split())
total=x-z
one_pair=y+z
k=1
while one_pair*k<total:
    k+=1
if one_pair*k%total==0:
    print(k)
else:
    print(k-1)
    