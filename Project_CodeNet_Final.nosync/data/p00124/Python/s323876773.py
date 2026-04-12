from collections import defaultdict
is_init = True
while True:
  n = int(input())
  if n == 0:
    break
  
  if is_init:
    is_init = False
  else:
    print()

  result = defaultdict(list)
  scores = set()
  for _ in range(n):
    name, w, l, d = input().split()
    score = int(w) * 3 + int(d)
    result[score].append(name)
    scores.add(score)
  
  scores = sorted(list(scores), reverse=True)
  for score in scores:
    for name in result[score]:
      print(name, score, sep=",")
