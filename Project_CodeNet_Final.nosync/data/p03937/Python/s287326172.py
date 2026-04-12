#coding:utf-8
H,W = map(int, input().split())
ans = 0
for h in range(H):
    S = str(input())
    for s in S:
        if s=="#":
            ans+=1
if (ans==H+W-1):
    print ("Possible")
else:
    print ("Impossible")