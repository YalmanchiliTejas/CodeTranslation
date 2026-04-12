X, Y, Z = map(int, input().split())
count = 0
X -= Z
while True:
    X -= Y 
    X -= Z
    if X < 0:
        break
    count += 1
print(count)
