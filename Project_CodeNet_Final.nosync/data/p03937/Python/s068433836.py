h, w = map(int, input().split())
fld = ''.join([input()for _ in range(h)])
if fld.count('#') == h+w-1:
    print('Possible')
else:
    print('Impossible')
