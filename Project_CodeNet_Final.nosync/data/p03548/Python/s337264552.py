X, Y, Z = map(int, input().split())
X -= Y + (Z * 2)
cnt = 1
cnt += X // (Y + Z)
print(cnt)