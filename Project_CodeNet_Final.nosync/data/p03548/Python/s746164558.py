X,Y,Z = map(int,input().split())
cnt = 0

while (X-Z) >= (Z+Y):
    X -= (Z+Y)
    cnt += 1
print(cnt)