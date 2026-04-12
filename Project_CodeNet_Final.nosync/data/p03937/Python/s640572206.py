h,w = map(int, input().split())
x = 0
for i in range(h):
    cells = input()
    if cells.find('#') == x:
        x = cells.rfind('#')
    else:
        print('Impossible')
        exit()
print('Possible')
