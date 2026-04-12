h,m = list(map(int,input().split()))

count = h+m

for i in range(h):
    b =(list(input()))
    count -= b.count('#')
if count == 1:
    print('Possible')
else:
    print('Impossible')