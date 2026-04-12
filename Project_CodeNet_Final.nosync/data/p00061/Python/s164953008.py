tp = {}
while 1:
	t,p = map(int,raw_input().split(","))
	if t == p == 0: break
	tp[t] = p
	
plist = sorted([tp[key] for key in tp.keys()],reverse = True)
prank = {}
rank = 1
point = plist[0]
for i in range(len(plist)):
	if plist[i] < point:
		point = plist[i]
		rank += 1
	prank[point] = rank
	
while 1:
	try:
		team = int(raw_input())
	except:
		break
	print prank[tp[team]]