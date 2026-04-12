lst = []

while True:
  p, s = map(int, input().split(","))
  if not p:
    break

  lst.append((s, p))

lst.sort(reverse=True)

dic = {}

rank = 0
solve_num = 0
for t in lst:
  if solve_num == t[0]:
    dic[t[1]] = rank
  else:
    rank += 1
    solve_num = t[0]
    dic[t[1]] = rank

while True:
  try:
    print(dic[int(input())])
  except EOFError:
    break

