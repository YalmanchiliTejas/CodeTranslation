x,y,z = map(int,input().split())
ans = 0
x-=z
while True:
    x-=y+z
    if x<0:
        break
    ans +=1
print(ans)