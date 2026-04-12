# -*- coding: utf-8 -*-

def main():
	a,b,c,x,y = map(int,input().split())
	if a+b < 2*c:
		# AピザとBピザ1枚ずつ用意するためにABピザ2枚より単体の方が安い場合
		print(a*x+b*y)
	else:
		# とりあえず必要数が少ない方に合わせて買う
		double = 2*c*min(x,y)
		if x < y:
			print((y-x)*min(b,2*c) + double)
		else:
			print((x-y)*min(a,2*c) + double)

if __name__ == '__main__':
    main()
