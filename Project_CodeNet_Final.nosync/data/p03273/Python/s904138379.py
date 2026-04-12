h,w = (int(i) for i in input().split())
a,b = [],["" for i in range(w)]
for _ in range(h):
	s = input()
	if s.count("#")!=0:
		a.append(s)
		for i in range(w): b[i]+=s[i]
num,ans = [True for i in range(w)],["" for i in range(len(a))]
for i in range(w):
	if b[i].count("#")==0: num[i] = False
for i in range(len(a)):
	for j in range(w):
		if num[j]: ans[i]+=a[i][j]
for i in ans: print(i)