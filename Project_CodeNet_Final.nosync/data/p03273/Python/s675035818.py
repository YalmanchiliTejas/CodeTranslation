H,W=map(int,input().split())
board=[list(input()) for i in range(H)]
print()

for i in range(H):
	emp=1
	for j in range(W):
		if(board[i][j]=='#'):
			emp=0
	if(emp==1):
		for j in range(W):
			board[i][j]='0'

for i in range(W):
	emp=1
	for j in range(H):
		if(board[j][i]=='#'):
			emp=0
	if(emp==1):
		for j in range(H):
			board[j][i]='0'
			
for i in range(H):
	out=""
	for j in range(W):
		out+=board[i][j] if board[i][j]!='0' else ""
	if out!="":
		print(out)