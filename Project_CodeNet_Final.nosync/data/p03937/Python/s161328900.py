h,w = map(int,input().split())
c = 0
for i in range(h):
    a = input()
    c += a.count('#')
if c == h + w - 1:
    print('Possible')
else:
    print('Impossible')