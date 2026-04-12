x,y,z = map(int,input().split())
ans = 0 
for i in range(100000):
    if (y+z)*i + z <= x:
        ans = i
    else:
        break
print(ans)