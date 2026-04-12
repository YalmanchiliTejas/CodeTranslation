a,b,c,x,y = map(int, input().split())

mi = a*x+b*y
#ABピザを買う枚数で全探索（探索範囲に注意）
for i in range(0,200000+1,2):
	#ABピザが2i枚であるとき、AピザおよびBピザはそれぞれi枚
	#それぞれ必要な枚数
	num_a = max(x - i//2, 0)
	num_b = max(y - i//2, 0)
	price = num_a*a + num_b*b + i*c
	if price < mi:
		mi = price

print(mi)