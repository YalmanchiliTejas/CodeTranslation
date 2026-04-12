import copy
n = int(input())
s = []
S = []
for i in range(n):
	s.append(input())
	S.append(sorted(s[i]))
minidx = 0
minlen = 0
for i in range(n):
	if minlen > len(S[i]):
		minidx = i
		minlen = len(S[i])
Slist = []
for i in range(n):
	if i != 0 and i != minidx:
		Slist.append(S[i])
	elif i == 0:
		Slist.append(S[minidx])
	elif i == minidx:
		Slist.append(S[0])
pword = copy.deepcopy(Slist[0])
word = []
for i in range(1,n):
	idx = 0
	pidx = 0
	while idx < len(Slist[i]) and pidx < len(pword):
		if pword[pidx]==Slist[i][idx]:
			word.append(pword[pidx])
			idx += 1
			pidx += 1
		elif pword[pidx] < Slist[i][idx]:
			pidx += 1
		elif pword[pidx] > Slist[i][idx]:
			idx += 1
	pword = copy.deepcopy(word)
	word = []
answer = ""
for i in range(len(pword)):
	answer += pword[i]
print(answer)