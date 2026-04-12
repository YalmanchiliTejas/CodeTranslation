x,y,z = map(int, input().split())
seated = z
cnt = 0
while True:
    seated += (y + z)
    if(seated > x):
        break
    cnt += 1
print(cnt)
