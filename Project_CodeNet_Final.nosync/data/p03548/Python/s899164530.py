X, Y, Z = map(int, input().split())

cnt = 0
X = X-Z
while(X > 0):
    X = X-Y-Z
    if X >= 0:
        cnt += 1
print(cnt)
