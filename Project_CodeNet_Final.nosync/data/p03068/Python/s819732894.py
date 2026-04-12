N = int(input())
S = input()
K = int(input())
t = S[K-1]
s = ""
for i in range(len(S)):
	s += ("*" if S[i] != t else t)
print(s)
