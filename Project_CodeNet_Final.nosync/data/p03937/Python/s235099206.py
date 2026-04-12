h,w=map(int,input().split())
sharp=0
for i in range(h):
    row=str(input())
    sharp += row.count('#')

if sharp==h+w-1:
    print('Possible')
else:
    print('Impossible')