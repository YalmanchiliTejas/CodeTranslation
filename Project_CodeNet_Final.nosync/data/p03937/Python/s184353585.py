H,W=map(int,input().split())
ans=0
for _ in range(H):
    s=input()
    A=list(x for x in s)
    ans+=A.count('#')
if ans==H+W-1:
    print('Possible')
else:
    print('Impossible')