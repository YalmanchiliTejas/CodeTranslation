h,w=map(int,input().split())
r=0
for _ in range(h):r+=input().count('#')
print('Possible'if r==h+w-1else'Impossible')