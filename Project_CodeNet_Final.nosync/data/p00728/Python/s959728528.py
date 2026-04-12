def main():
	while True:
		n=int(input())
		if n==0:
			break
		ls=[int(input()) for i in range(n)]
		ls.sort()
		score_sum=sum(ls)-ls[0]-ls[n-1]
		print(int(score_sum//(n-2)))

if __name__=="__main__":
	main()

