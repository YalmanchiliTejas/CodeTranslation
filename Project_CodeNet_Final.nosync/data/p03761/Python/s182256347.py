import sys
input=sys.stdin.readline
n=int(input())
INF=10**9
D=[INF]*26
for i in range(n):
    d=[0]*26
    s=input().rstrip()
    for j in s:
        d[ord(j)-97]+=1
    for j in range(26):
        D[j]=min(D[j],d[j])
allzero=True
for i in range(26):
    if D[i]!=0:
        allzero=False
    print((chr(i+97))*D[i],end='')
if allzero:
    print('')
