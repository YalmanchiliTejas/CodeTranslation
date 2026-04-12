X, Y, Z = map(int, input().split())
ans = 0

for i in range(1, X):
    if i*Y+(i+1)*Z <= X:
        ans = i
    else:
        break
print(ans)
