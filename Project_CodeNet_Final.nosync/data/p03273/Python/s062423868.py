import numpy as np
h, w = list(map(int, input().split()))
loc_array = [list(input().replace("#", "1").replace(".", "0")) for _ in range(h)]
loc_array = np.array([list(map(int, l)) for l in loc_array])
row_sum = loc_array.sum(axis=1)
col_sum = loc_array.sum(axis=0)
while 0 in row_sum or 0 in col_sum:
  row_rm = [i for i, r in enumerate(row_sum) if r == 0]
  loc_array = np.delete(loc_array, row_rm, axis=0)
  col_rm = [i for i, c in enumerate(col_sum) if c == 0]
  loc_array = np.delete(loc_array, col_rm, axis=1)
  row_sum = loc_array.sum(axis=1)
  col_sum = loc_array.sum(axis=0)

loc_str = [list(map(str, loc_array[i,:])) for i in range(loc_array.shape[0])]
loc_str = ["".join(l).replace("1", "#").replace("0", ".") for l in loc_str]
for l in loc_str:
  print(l)
