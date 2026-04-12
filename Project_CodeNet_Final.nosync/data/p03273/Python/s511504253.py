def remove_row(l):
  ret = []
  for row in l:
    s = row[0]
    if any([e == "#" for e in s]):
      ret.append(row)
      
  return ret

def remove_col(l,w):
  num_row = len(l)
  num_col = w
  ret = [[""] for _ in range(num_row)]
  for i in range(num_col):
    if any([l[j][0][i] == "#" for j in range(num_row)]):
      for k in range(num_row):
        ret[k] = [ret[k][0] + l[k][0][i]]
        
  return ret


h, w = map(int, input().split())
l = [input().split() for _ in range(h)]

l = remove_row(l)
l = remove_col(l,w)
for e in l:
  print(e[0])