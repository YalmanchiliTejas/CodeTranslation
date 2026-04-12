N,*A = map(int,open(0).read().split())

S_all = sum(A)**2
diag = sum([a**2 for a in A])

S = S_all-diag
S %= 1000000007
S = (S*pow(2,-1,1000000007))%1000000007

print(S)
