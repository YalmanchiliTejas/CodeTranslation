a, b, c, x, y = map(int, input().split())
ans = 999999999999999
for i in range(10 ** 5+1):
  	# maxの部分はx-iまたはy-iが負になったときに0を返すために用いてる
    ans = min(ans, i * 2*c + max(0, x-i) * a + max(0, y-i)*b)
print(ans)
