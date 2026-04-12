n=int(input())
Hs=[]
cnt=0
for h in input().split():
	h = int(h)
	Hs.append(h)
	if max(Hs) == h:
		cnt += 1
print(cnt)
