def calc(n, k):
	if n == 0:
		return 1
	if k == 1:
		return 0
	len = 2**(n+1)-3 # 1+len+1+len+1
	if k <= len+1:
		return calc(n-1, k-1)
	if k == len+2:
		return calc(n-1, len)+1
	if k <= len+len+2:
		return calc(n-1, len)+1+calc(n-1, k-len-2)
	if k == len+len+3:
		return 2**(n+1)-1

n, k = map(int, input().split())
print(calc(n, k))