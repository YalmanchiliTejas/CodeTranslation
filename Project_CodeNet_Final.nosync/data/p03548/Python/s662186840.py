x,y,z = map(int,input().split())
total = 0
ans = 0

while total <= x-z:
    total += y+z
    ans += 1
print(ans-1)
