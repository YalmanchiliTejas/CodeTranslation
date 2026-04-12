A, B, C, X, Y = map(int, input().split())

ans = 10 ** 12
for i in range(10 ** 5 + 1):#2 * i枚のABピザを購入
  money = 2 * i * C
  money += A * max(0, X - i)
  money += B * max(0, Y - i)
  ans = min(ans, money)
  
print(ans)  