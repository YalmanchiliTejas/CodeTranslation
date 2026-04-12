# all n integers can be divided into blocks of integers of size i  and in each 
# there will be total i-k integers which has remainder greater than k so we multiply this with no of blocks
# if there is a last block remaining we add all integers with remainder greater than k
def main():
	n , k = map(int , input().split())
	ans = 0
	for i in range(k+1 , n+1):
		ans = ans+(n//i*(i-k))
		if n%i>0:
			if k==0:
				ans = ans+n%i
			else:
				ans =ans +max(0 , n%i-k+1)
	print(ans)
if __name__=="__main__":
	main()