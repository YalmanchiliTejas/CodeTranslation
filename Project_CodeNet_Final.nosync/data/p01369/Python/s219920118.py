lefts = ['q','w','e','r','t','a','s','d','f','g','z','x','c','v','b']

while(True):
  strs = input()
  if strs == '#':
    break
  side_pre = 0
  side_now = 0
  mv_cnt = 0
  for i in range(len(strs)):
    c = strs[i]
    if strs[i] in lefts:
      side_now = 1
    else:
      side_now = -1
    if side_pre == 0:
      side_pre = side_now
    if side_now != side_pre:
      mv_cnt += 1
    side_pre = side_now
  print(mv_cnt)
