x,y,z = map(int,input().split())
cnt=0
s=z+z+y
while(True):
    if s>x:
        break
    else:
        cnt+=1
    s+=y+z
print(cnt)    