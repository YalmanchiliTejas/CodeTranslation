H,W=map(int, input().split())
a = [input() for i in range(H)]

ans=0
cnt=0
 
for i in range(H-1):
    for j in range(W-1):
        if a[i][j] == '#' and a[i+1][j] == '#' and  a[i][j+1] == '#':
            cnt+=1
        elif a[i][j] == '#' and a[i+1][j] == '.' and  a[i][j+1] == '.':
            cnt+=1

            
for i in range(1,H):
    for j in range(1,W):
        if a[i][j] == '#' and a[i-1][j] == '.' and  a[i][j-1] == '.':
            cnt+=1

        
print('Impossible' if cnt>0 else 'Possible')