X,Y,Z = map(int,input().split())
ans, r = divmod(X,(Y+Z))
if r < Z: ans -= 1
print(ans)