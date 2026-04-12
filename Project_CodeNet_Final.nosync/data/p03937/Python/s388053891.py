from collections import deque
h,w = map(int,input().split())

Map = []
Cnt = 0
for i in range(h):
    tmp = list(input())
    Cnt += tmp.count('#')
    Map.append(tmp)
q = deque()
q.append((0,0,0,True))
while q:
    y,x,cnt,flag= q.pop()
    if flag ==False:
        continue
    if y<0 or y>=h or x<0 or x>=w:
        continue
    if Map[y][x]!='#':
        continue
    cnt += 1
    if cnt==Cnt and y==h-1 and x == w-1:
        if flag:
            print('Possible')
        exit()
    q.append((y+1,x,cnt,flag))
    q.append((y,x+1,cnt,flag))
    flag = False
    q.append((y-1,x,cnt,flag))
    q.append((y,x-1,cnt,flag))

print('Impossible')