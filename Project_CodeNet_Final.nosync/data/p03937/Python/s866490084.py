import collections
H, W = map(int, input().split())
A = [input() for _ in range(H)]
A = [a+'.' for a in A]
A.append('.'*(W+1))

cnt = -1
for a in A:
    cnt += a.count('#')

i=j=0
flg=False
while True:
    if (A[i][j+1]=='#' and A[i+1][j]=='.'):
        j += 1
        cnt -= 1
    elif (A[i][j+1]=='.' and A[i+1][j]=='#'):
        i += 1
        cnt -= 1
    else:
        break
    
    if i==H-1 and j==W-1 and cnt==0:
        flg=True
        break

ans = 'Possible' if flg else 'Impossible'
print(ans)
        