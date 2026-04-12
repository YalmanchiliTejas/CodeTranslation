from statistics import mean
while True:
  N = int(input())
  if N == 0:
    break
  S = []
  for i in range(N):
    S.append(int(input()))
  S.remove(max(S))
  S.remove(min(S))
  print(int(mean(S)))

