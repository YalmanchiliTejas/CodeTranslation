H, W = map(int, input().split())
A = [input() for i in range(H)]

here = 0
for i in A:
    if here != i.find('#'):
        print('Impossible')
        exit()
    else:
        here = i.rfind('#')
else:
    print('Possible')