def countInn(n, L):
  numInn = 1
  mainHurdle = L[0]
  hurdle = mainHurdle
  for i in range(1, n):
    currentH = L[i]
    if currentH < mainHurdle or currentH < hurdle:
      continue
    numInn += 1
    hurdle = currentH
  print(numInn)
  
n = int(input())
a = list(map(int, input().split()))
countInn(n, a)
