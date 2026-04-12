X, Y, Z = map(int, input().split())
cnt = 0
for i in range(1,X):
    if X >= i*Y + (i+1)*Z:
        cnt += 1
print(cnt)