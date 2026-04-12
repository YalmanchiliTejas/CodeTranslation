h,w = map(int,input().split())
cnt = 0
for i in range(h):
    s = input()
    cnt += s.count('#')
if cnt==h+w-1:
    print('Possible')
else:
    print('Impossible')