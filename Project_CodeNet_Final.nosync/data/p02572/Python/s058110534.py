n = int(input())
lst = list(map(int, input().split()))
	
suffS = []
lst = lst[::-1]
summ = 0
for i in lst:
	suffS.append(summ)
	summ += i
res = 0
for i in range(n):
	res += suffS[i] * lst[i]
	res %= (10**9+7)
print(res)
