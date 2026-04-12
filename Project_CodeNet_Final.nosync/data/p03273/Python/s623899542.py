H,W = map(int,input().split())
list_ = []
result = []
a = []
for i in range(H):
  tmp_set = list(input())
  if set(tmp_set) != {'.'}:
    list_.append(tmp_set)
    
for i in range(len(list_[0])):
  dot_ = 0
  a = [x[i] for x in list_]
  if set(a)!={'.'}:
    result.append(a)
    	
result = [list(x) for x in zip(*result)]
for i in result:
  print(''.join(i))