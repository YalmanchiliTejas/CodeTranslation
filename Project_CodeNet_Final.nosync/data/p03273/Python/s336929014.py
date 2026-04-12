import numpy as np
h, w = map(int, input().split())

amap = []
# 横一列に"#"が含まれている場合はamapにappendする
for _ in range(h):
  a = input()
  if "#" in a:
    amap.append(a)

bmap = []
# 縦一列に"#"が含まれている場合はbmapにappendする
for wid in range(w):
  b = [amap[hei][wid] for hei in range(len(amap))]
  if "#" in b:
    bmap.append(b)

bmap = np.array(bmap)
tbmap = bmap.T

for i in tbmap:
  print(''.join(i))