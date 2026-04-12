# r,g,bにそれぞれ代入
r, g, b = map(int, input().split())
# 3桁の整数を作る
num = (r * 100) + (g * 10 ) + b
#4の倍数か判定
if num % 4 == 0: #numを4で割った余りが0
	print('YES')
else:
	print('NO')  