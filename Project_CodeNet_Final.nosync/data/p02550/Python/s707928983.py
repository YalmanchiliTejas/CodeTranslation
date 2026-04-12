
import sys
from sys import stdin

N,X,mod = map(int,input().split())

db = [ [0] * 40 for i in range(mod) ]
s = [ [0] * 40 for i in range(mod) ]

for i in range(mod):

    db[i][0] = i*i%mod
    s[i][0] = i


for j in range(1,40):
    for i in range(mod):

        db[i][j] = db[db[i][j-1]][j-1]
        s[i][j] = s[i][j-1] + s[db[i][j-1]][j-1]

now = X
ans = 0

#print (db[0:10])

for i in range(39,-1,-1):

    #print (now)
    if N & (2**i) > 0:
        ans += s[now][i]
        now = db[now][i]

print (ans)
