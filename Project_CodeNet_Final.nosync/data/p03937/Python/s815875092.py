h, w = map(int, input().split())
a = []
for i in range(h):
    a.append((input()))
for i in range(h-1):
    if((w-a[i][::-1].index('#')-1) > a[i+1].index('#')):
        print('Impossible')
        exit()
print('Possible')