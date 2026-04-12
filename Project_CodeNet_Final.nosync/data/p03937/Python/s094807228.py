# coding: utf-8
# Your code here!
n,m=map(int,input().split())
s = [list(input()) for i in range(n)]
cnt=0
for i in range(n):
    for j in range(m):
        if s[i][j]=='#':
            cnt+=1
if cnt>n+m-1:
    print('Impossible')
else:
    print('Possible')
