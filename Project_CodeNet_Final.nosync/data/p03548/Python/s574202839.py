X, Y, Z = map(int, input().split())
cnt = 0
X -= Z
cnt += X//(Y+Z)
print(cnt)