n, m = map(int, input().split())

dic = {}
for i in range(1, n+1):
  dic[i] = []
for i in range(m):
  a1, a2 = map(int, input().split())
  dic[a1] += [a2]
  dic[a2] += [a1]

def next_position(position, history, dic):
  next_you_can_move = list(set(dic[position]) - set(history))
  return next_you_can_move

def serch(position, history, dic):
  counter = 0
  if len(history) == n:
    return 1
  else:
    next_you_can_move = next_position(position, history, dic)
    if next_you_can_move == []:
      return 0
    for cand in next_you_can_move:
      new_history = history + [cand]
      counter += serch(cand, new_history, dic)
    return counter
count = serch(1, [1], dic)
print(count)