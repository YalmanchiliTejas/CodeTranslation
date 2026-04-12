import sys
h, w = map(int, input().split())
i = 0
pos = 0
while h > i:
    s = input()
    l = s.find('#')
    r = s.rfind('#')
    if (l == pos and r >= pos):
        pos = r
        i += 1
    else:
        print('Impossible')
        sys.exit()
print('Possible')
