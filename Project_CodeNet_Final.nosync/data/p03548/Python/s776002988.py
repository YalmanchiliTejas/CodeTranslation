X,Y,Z = map(int, input().split())
x = X - Z
ans = x // (Y+Z)
print(ans)