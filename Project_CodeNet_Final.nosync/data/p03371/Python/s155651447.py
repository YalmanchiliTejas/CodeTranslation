A,B,C,X,Y = map(int, input().split())
AB = 2 * C
mn = AB * max(X, Y)
for i in range(max(X, Y) + 1):
  mn = min(mn, A * max(0, X - i) + B * max(0, Y - i) + AB * i)
print(mn)