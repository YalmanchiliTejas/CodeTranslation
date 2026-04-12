h,w = map(int,input().split())
f = [input()for _ in range(h)]
res = 0
for  i in range(h):
    res += f[i].count('#')
if res  == h+w-1:print('Possible')
else:print('Impossible')
