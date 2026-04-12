from functools import reduce
H, W =  map(int,input().split())
list1 = [input() for i in range(H)]
row_index = []
column_index =[]
[row_index.append(i) for i, elem in  enumerate(list1) if elem.count(".") < W]
[column_index.append(i) for i,elem in enumerate(zip(*list1)) if elem.count(".")<H]
for i in  row_index:
  for j in column_index:
    print(list1[i][j],end="")
  print("")
