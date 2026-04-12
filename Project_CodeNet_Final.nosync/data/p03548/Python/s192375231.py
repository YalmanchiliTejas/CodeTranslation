x,y,z = map(int,input().split())
ans = 0
for i in range(10**5):
    if i*y + (i+1)*z <= x:
        pass
    else:
        break
print(i-1)