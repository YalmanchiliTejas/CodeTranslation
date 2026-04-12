while True :
	x = list(input())
	if(x[0] == "#") :
		break
	else :
		left = "qwertasdfgzxcvb"
		right = "yuiophjklnm"
		cnt = 0
		for i in range(len(x) - 1) :
			L = x[i] in left and x[i + 1] in left
			R = x[i] in right and x[i+1] in right
			if(L or R) :
				pass
			else :
				cnt += 1
		print(cnt)
