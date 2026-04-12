x,y,z = map(int,input().split())

ans = 0
for i in range(x):
    if (i+1)*z +i*y <= x:
        ans = i
    else:
        break

print(ans)