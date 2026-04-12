while True:
  dice = [1,2,3,5,4,6]
  n = int(input())
  if n == 0:
    break
  a = 1
  while n>0:
    s = input()
    if s == 'North':
      dice[0],dice[1],dice[3],dice[5] = dice[1],dice[5],dice[0],dice[3]
    elif s == 'South':
      dice[1],dice[5],dice[0],dice[3] = dice[0],dice[1],dice[3],dice[5]
    elif s == 'East':
      dice[0],dice[2],dice[4],dice[5] = dice[4],dice[0],dice[5],dice[2]
    elif s == 'West':
      dice[4],dice[0],dice[5],dice[2] = dice[0],dice[2],dice[4],dice[5]
    elif s == 'Right':
      dice[1],dice[2],dice[3],dice[4] = dice[2],dice[3],dice[4],dice[1]
    else:
      dice[2],dice[3],dice[4],dice[1] = dice[1],dice[2],dice[3],dice[4]
    a += dice[0]
    n -= 1
  print(a)
