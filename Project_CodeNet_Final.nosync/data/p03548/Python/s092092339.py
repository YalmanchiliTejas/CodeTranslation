x,y,z = map(int,input().split())
ans = 0
length = z
for i in range(x):
    length += y+z
    if length <= x:
        ans += 1
    else:
        break
print(ans)