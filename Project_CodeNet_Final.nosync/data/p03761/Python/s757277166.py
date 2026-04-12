n = (int)(input())
alp = [10000 for i in range(0 , 90)] # initialize to infinity
for i in range(0 , n):
	s = input()
	now = [0 for i in range(29)]
	for i in s:
		now[ord(i)-ord('a')]+=1 # counting letters
	for i in range(0  ,27):
		alp[i]=min(alp[i], now[i])# consider minimum frequency of every letter occuring in the string
res = ""
for i in range(0 , 26):
	if alp[i]>=1:
		res = res+"".join(([(chr(i+ord('a')))]*alp[i])) # very complex
print(res)