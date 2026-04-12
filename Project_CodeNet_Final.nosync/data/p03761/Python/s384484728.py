#ABC058C
N=int(input())
d={}
for n in range(N):
	S=input()
	for a in [chr(ord('a') + i) for i in range(26)]:
		d[a]=min(d.get(a,100),S.count(a))
for a in [chr(ord('a') + i) for i in range(26)]:
	print(a*d[a],end='')
print()