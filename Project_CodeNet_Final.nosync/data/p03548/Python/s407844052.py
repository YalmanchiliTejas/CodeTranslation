X, Y, Z = map(int, input().split())
ans = 0
for i in range(1, X // Y + 1):
    if X - Y * i - (i + 1) * Z >= 0:
        ans = i
    else:
        break
print(ans)