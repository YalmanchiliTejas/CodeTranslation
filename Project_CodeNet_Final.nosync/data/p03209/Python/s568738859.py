N,X = list(map(int,input().split()))

n_patties = {0:1}
l_burgur = {0:1}
for i in range(N):
  n_patties[i+1] = n_patties[i]*2+1
  l_burgur[i+1] = l_burgur[i]*2+3 

def cnt_patty(level,x):
  if x == l_burgur[level]:
    return n_patties[level]
  elif l_burgur[level-1] + 2 < x:
    return n_patties[level-1] + 1 + cnt_patty(level-1,x-l_burgur[level-1]-2)
  elif l_burgur[level-1] + 2 == x:
    return n_patties[level-1] + 1
  elif 1 < x:
    return cnt_patty(level-1,x-1)
  else:
    return 0

print(cnt_patty(N,X))