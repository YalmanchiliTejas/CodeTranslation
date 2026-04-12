import sys
h,w = map(int,input().split())
A = []
for i in range(h):
    A.append(list(input()))
dx = [1,0,]
dy = [0,1,]
B = [[0,0]]
while B:
    S = B.pop()
    cnt = 0
    if S == [w-1,h-1]:
        A[h-1][w-1] = "."
        for L in A:
            if L.count("#") != 0:
                print("Impossible")
                sys.exit()
        else:
            print("Possible")
            break
    for i in range(2):
        x = S[0] + dx[i]
        y = S[1] + dy[i]
        if 0 <= x <= w-1 and 0 <= y <= h-1 and A[y][x] == "#":
            B.append([x,y])
            cnt += 1
    else:
        if cnt != 1:
            print("Impossible")
            break
        else:
            A[S[1]][S[0]] = "."
        
        
            
