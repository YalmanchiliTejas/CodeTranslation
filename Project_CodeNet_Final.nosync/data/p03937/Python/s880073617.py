h,w = map(int,input().split())
a = [input().count('#') for i in range(h)]
print('Possible' if sum(a)==h+w-1 else 'Impossible')