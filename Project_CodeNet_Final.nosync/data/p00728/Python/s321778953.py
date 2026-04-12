def calc_score(list):
    list.remove(max(list))
    list.remove(min(list))
    return int(sum(list) / len(list))

while True:
  grader = int(input())
  if grader == 0:
      break
  scores = [int(input()) for _ in range(grader)]
  print(calc_score(scores))

