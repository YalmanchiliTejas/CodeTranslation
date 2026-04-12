a,b,c,x,y = map(int,raw_input().split())

money = 0
if a + b > c * 2 :

	c_num = y * 2 if x > y else x * 2 #x > y ? y*2 : x*2
	money += c * c_num

	rest_money = a if x > y else b #x > y ? a : b
	rest_num = x-y if x > y else y-x #x > y ? x-y : y-x
	
	money += c * 2 * rest_num if rest_money > c*2 else rest_money * rest_num

else :
	money += a * x + b * y

print money 
