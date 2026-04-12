from collections import Counter
H,W = map(int,input().split())
src = [input() for i in range(H)]
ctr = Counter()
for row in src:
    ctr.update(row)
print('Possible' if ctr['#'] == H+W-1 else 'Impossible')