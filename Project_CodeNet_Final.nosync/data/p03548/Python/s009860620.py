
x,y,z = map(int,input().split())

ans = 0

while (y + z) * ans <= (x - z):
    ans += 1
#    print((y + z) * ans)
#    print(ans)

print(ans-1)
