A,B,C,X,Y = map(int,input().split())
c = []
for i in range(10 ** 5 + 1):
  cash = 2 * C * i + A * max(0,X - i) + B * max(0, Y - i)
  c.append(cash)
print(min(c))