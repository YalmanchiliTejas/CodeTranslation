x, y, z = map(int, input().split())
ans = 1
capa = 0
while True:
    capa = ans * y + ans * z + z
    if capa > x:
        break
    ans += 1
print(ans-1)