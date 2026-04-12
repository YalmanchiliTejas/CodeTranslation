N = int(input())
H_li = list(map(int, input().split(' ')))

def check(H):
  H_max = max(H_li)
  max_indexs = ([i for i, x in enumerate(H_li) if x == H_max])

  if len(max_indexs) > 1:
    max_index = max(max_indexs)
    return max_index
  else:
    return max_indexs[0]


max_index = check(H_li)

S = 0

for i in range(max_index):
  num = max_index - i
  try:
    if max(H_li[:num]) <= H_li[num]:
    	S += 1
  except:
    pass
    
print(S+1)


 