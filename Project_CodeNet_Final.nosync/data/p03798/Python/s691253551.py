N = int(input())
S = input()

## 0:sheep, 1:wolf
first_state_circle = [[0,0,0],[0,1,1],[1,0,1],[1,1,0]] ## [1st,2nd,-1th]
first_state_cross = [[0,0,1],[0,1,0],[1,0,0],[1,1,1]] ## [1st,2nd,-1th]
transtable = str.maketrans({'0':'S', '1':'W'})

if S[0] == 'o':
  first_state = first_state_circle
else:
  first_state = first_state_cross

for state in first_state:
  lst = [-1]*N
  lst[0] = state[0]
  lst[1] = state[1]
  for i in range(1,N-1):
    lst[i+1] = (lst[i-1] + lst[i] + (S[i]=='x')) % 2
  #print(state,lst)
  if lst[N-1] != state[2]:
    continue
  if lst[0] != (lst[N-2] + lst[N-1] + (S[N-1]=='x')) % 2:
    continue
  ans = ''.join(map(str,lst)).translate(transtable)
  print(ans)
  exit()
else:
  print('-1')