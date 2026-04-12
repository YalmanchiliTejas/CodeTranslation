memo = [[0, 1]]

def f(n, b, p, k):
	if b+p == k: return [b, p]
	if n == 0: return [b, p+1]
	newlst1 = [b+1, p]
	if newlst1[0]+newlst1[1] == k: return newlst1
	newlst2 = [newlst1[0]+memo[n-1][0], newlst1[1]+memo[n-1][1]]
	if newlst2[0] + newlst2[1] == k: return newlst2
	if newlst2[0] + newlst2[1] > k: return f(n-1, newlst1[0], newlst1[1], k)
	newlst3 = [newlst2[0], newlst2[1]+1]
	if newlst3[0]+newlst3[1] == k: return newlst3
	newlst4 = [newlst3[0]+memo[n-1][0], newlst3[1]+memo[n-1][1]]
	if newlst4[0]+newlst4[1] == k: return newlst4
	if newlst4[0]+newlst4[1] > k: return f(n-1, newlst3[0], newlst3[1], k)
	return [newlst4[0]+1, newlst4[1]]

N, K = map(int, input().split())
for i in range(1, N):
	memo.append([2*memo[i-1][0]+2, 2*memo[i-1][1]+1])
print(f(N, 0, 0, K)[1])