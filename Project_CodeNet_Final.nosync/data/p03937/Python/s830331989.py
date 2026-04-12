h,w=map(int, input().split())
a=[list(input()) for i in range(h)]
count=0
for i in a:
    count+=i.count('#')
if count==h+w-1:print('Possible')
else:print('Impossible')