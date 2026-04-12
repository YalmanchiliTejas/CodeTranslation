def solve(n,A):
	mod=10**9+7
	s=0
	for _,x in enumerate(A):
		s+=x
	s=s**2
	squared_terms=0
	for _,x in enumerate(A):
		y=x**2
		squared_terms+=y
	ans=(s-squared_terms)//2
	return ans%mod


N=int(input())
A=list(map(int,input().split()))
print(solve(N,A))