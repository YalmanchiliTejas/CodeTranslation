
n = int(input())

all_ord_list = [ None for i in range(n) ] 
def listing(inlist):
	ord_list = [0 for i in range(26)]
	for i in inlist:
		ord_list[ord(i)-97] += 1
	return ord_list

for i in range(n):
	all_ord_list[i] = listing(input())

ans = ""
for i in range(26):
	ans += (min([ all_ord_list[j][i] for j in range(n)])*chr(97+i))
	
print(ans)