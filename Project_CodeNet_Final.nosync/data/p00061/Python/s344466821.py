# AOJ 0061 Rank Checker
# Python3 2018.6.15 bal4u

team = {}
while True:
	p, s = list(map(int, input().split(',')))
	if p == 0: break
	team[p] = s
tbl = sorted(team.items(), key=lambda x:x[1], reverse=True)

ans = [0]*101
ans[tbl[0][0]] = ord = 1
for i in range(1,len(tbl)):
	if tbl[i][1] < tbl[i-1][1]: ord += 1
	ans[tbl[i][0]]= ord
	
while True:
    try:
        print(ans[int(input())])
    except EOFError:
        break
