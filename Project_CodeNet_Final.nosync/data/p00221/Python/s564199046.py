while True:
  m, n = map(int, input().split())
  if m == 0:
    break

  plst = [i for i in range(1, m + 1)]
  length = m
  ind = 0
  for i in range(1, n + 1):
    s = input()
    if length == 1:
      continue
    if i % 15 == 0:
      if s != "FizzBuzz":
        plst.pop(ind)
        length -= 1
        ind %= length
      else:
        ind += 1
        ind %= length
    elif i % 5 == 0:
      if s != "Buzz":
        plst.pop(ind)
        length -= 1
        ind %= length
      else:
        ind += 1
        ind %= length
    elif i % 3 == 0:
      if s != "Fizz":
        plst.pop(ind)
        length -= 1
        ind %= length
      else:
        ind += 1
        ind %= length
    else:
      if s != str(i):
        plst.pop(ind)
        length -= 1
        ind %= length
      else:
        ind += 1
        ind %= length
  print(*plst)
