if __name__ == '__main__':

	a,b,c,x,y = map(int,input().split())

	#A,Bのみで買った場合
	tmp1 = (a * x) + (b * y)

	#A-Bで買った場合 量は2倍になる
	mi = min(x,y)

	tmp2 = mi * c * 2

	#A-Bで買った場合 残りの判定
	if x - mi == 0:
		#Bをそのまま買う
		tmp3 = b * (y - mi)
		
		#ABを買う(残りのAは捨てる)
		tmp4 = c * (y - mi) * 2
		
		tmp2 += min(tmp3,tmp4)
		
	else:
		#Aをそのまま買う
		tmp3 = a * (x - mi)
		
		#ABを買う(残りのBは捨てる)
		tmp4 = c * (x - mi) * 2
		
		tmp2 += min(tmp3,tmp4)

	#判定
	print(min(tmp1,tmp2))

