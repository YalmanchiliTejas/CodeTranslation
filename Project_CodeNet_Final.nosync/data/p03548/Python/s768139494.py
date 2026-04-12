# input
X, Y, Z = map(int, input().split())

X = X - Z

ans = X // (Y + Z)

print(ans)
