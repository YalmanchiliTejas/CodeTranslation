x,y,z = map(int, input().split())
width = x-z
ans = 0
while width >= 0:
    width -= y+z
    ans += 1
print(ans-1)