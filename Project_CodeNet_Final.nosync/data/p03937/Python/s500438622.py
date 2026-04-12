H,W=map(int,input().split())
C=[input() for i in range(H)]
F=[[0 for i in range(W)] for j in range(H)]
cc=0
for i in range(H):
    cc+=list(C[i]).count('#')
C[0]='s'+C[0][1:]
C[-1]=C[-1][:-1]+'g'
for i in range(H):
	if('s' in C[i]):
		home_y=i
		home_x=C[i].index('s')
	if('g' in C[i]):
		store_y=i
		store_x=C[i].index('g')

stack=[[home_x,home_y]]

def check(x,y):
	if(x<0 or x>=W or y<0 or y>=H):
		return 0
	if(C[y][x]=='.'):
		return 0
	if(F[y][x]==1):
		return 0
	return 1

while(len(stack)!=0):
    x,y=stack.pop()
    F[y][x]=1
    if(check(x+1,y)):
        stack.append([x+1,y])
    #if(check(x-1,y)):
        #stack.append([x-1,y])
    if(check(x,y+1)):
        stack.append([x,y+1])
    #if(check(x,y-1)):
        #stack.append([x,y-1])
    #print(stack)

if(F[store_y][store_x]==1) and cc==H+W-1:
	print('Possible')
else:
	print('Impossible')
#print(F)

