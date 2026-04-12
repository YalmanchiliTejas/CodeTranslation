X,Y,Z = map(int,input().split())

X = X - Z
ans = int(X/(Y+Z))
print(ans)