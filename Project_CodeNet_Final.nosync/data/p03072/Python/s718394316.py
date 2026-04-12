
def main():
	N = int(input())
	H = list(map(int,input().split()))
	
	count = 1
	for i,ryokan in enumerate(H[1:]) :
		flag = False
		for o in H[:i+1] :
			if o <= ryokan :
				flag = True
			else :
				flag = False
				break
		if flag == True :
			count += 1
	print(count)

if __name__ == "__main__" :
	main()