h,w = map(int,input().split())
count = 0
for i in range(h):
    a = input()
    for j in a:
        if j == '#':
            count += 1
if count == h + w -1:
    print('Possible')
else:
    print('Impossible')
    
