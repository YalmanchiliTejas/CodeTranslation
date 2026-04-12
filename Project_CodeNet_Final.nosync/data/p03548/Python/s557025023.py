X, Y, Z = map(int, input().split())
ans = 1
X -= Y+2*Z
ans += X//(Y+Z)
print(ans)