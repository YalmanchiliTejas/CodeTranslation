H,W=map(int,input().split())
S=[]
for _ in range(H):
    s=input()
    s=[a for a in s]
    S.append(s)
visited=[[-1 for _ in range(W)] for _ in range(H)]
visited[0][0]=1
stack=[[0,0]]
answer=0
S[0][0]='.'
while len(stack)>0:
    h,w=stack.pop()
    number=0
    for x,y in ([0,1],[0,-1],[1,0],[-1,0]):
        new_w=w+x
        new_h=h+y
        if new_w<0 or new_w>=W or new_h<0 or new_h>=H:
            continue
        elif visited[new_h][new_w]==-1 and S[new_h][new_w]=='#':
            number+=1
            visited[new_h][new_w]=1
            S[new_h][new_w]='.'
            stack.append([new_h,new_w])
            if x==-1 and y==0:
                answer=1
                break
            elif x==0 and y==-1:
                answer=1
                break
        if number>1:
            answer=1
            break
if answer==0:
    print('Possible')
else:
    print('Impossible')
