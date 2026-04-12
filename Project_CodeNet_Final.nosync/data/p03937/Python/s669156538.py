h,w = list(map(int, input().split()))
a = [input() for _ in range(h)]
ftpcount = 0
for i in a:
    ftpcount += i.count('#')

print('Possible' if ftpcount==h+w-1 else 'Impossible')