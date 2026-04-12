n = (int)(input())
alp = [10000 for i in range(0 , 90)]
for i in range(0 , n):
	s = input()
	now = [0 for i in range(29)]
	for i in s:
		now[ord(i)-ord('a')]+=1
	for i in range(0  ,27):
		alp[i]=min(alp[i], now[i])
res = ""
for i in range(0 , 26):
	if alp[i]>=1:
		res = res+"".join(([(chr(i+ord('a')))]*alp[i]))
print(res)