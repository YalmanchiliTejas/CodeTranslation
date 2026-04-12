h,w=map(int, input().split())
s=[list(input()) for i in range(h)]
ans=0
for i in s:
    ans+=i.count('#')
if ans==h+w-1:print('Possible')
else:print('Impossible')