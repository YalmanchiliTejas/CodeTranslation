h,w = map(int,input().split())
s = ''
for i in range(h):
    s += (input())
if s.count('#') == h + w - 1:
    print('Possible')
else:
    print('Impossible')
