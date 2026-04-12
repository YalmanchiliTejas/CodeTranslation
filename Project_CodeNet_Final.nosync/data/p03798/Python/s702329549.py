N = int(input())
s = input()

sl = list(s)

def calc(i, resl):
  now = resl[i]
  back = resl[i-1]

  if now == 'W':
    if back == 'W':
      if sl[i] == 'o':
        resl[i+1] = 'S'
      else:
        resl[i+1] = 'W'
    else:
      if sl[i] == 'o':
        resl[i+1] = 'W'
      else:
        resl[i+1] = 'S'
  else: # 'S'
    if back == 'W':
      if sl[i] == 'o':
        resl[i+1] = 'W'
      else:
        resl[i+1] = 'S'
    else:
      if sl[i] == 'o':
        resl[i+1] = 'S'
      else:
        resl[i+1] = 'W'

def test2(resl):
  i = 0
  now = resl[0]
  back = resl[-1]
  
  if now == 'W':
    if back == 'W':
      if sl[i] == 'o':
        return resl[1] == 'S' and test2
      else:
        return resl[1] == 'W' and test2
    else:
      if sl[i] == 'o':
        return resl[1] == 'W' and test2
      else:
        return resl[1] == 'S' and test2
  else: # 'S'
    if back == 'W':
      if sl[i] == 'o':
        return resl[1] == 'W' and test2
      else:
        return resl[1] == 'S' and test2
    else:
      if sl[i] == 'o':
        return resl[1] == 'S' and test2
      else:
        return resl[1] == 'W' and test2


def test(resl):
  i = N-1
  now = resl[-1]
  back = resl[-2]
  
  if now == 'W':
    if back == 'W':
      if sl[i] == 'o':
        return resl[0] == 'S' and test2(resl)
      else:
        return resl[0] == 'W' and test2(resl)
    else:
      if sl[i] == 'o':
        return resl[0] == 'W' and test2(resl)
      else:
        return resl[0] == 'S' and test2(resl)
  else: # 'S'
    if back == 'W':
      if sl[i] == 'o':
        return resl[0] == 'W' and test2(resl)
      else:
        return resl[0] == 'S' and test2(resl)
    else:
      if sl[i] == 'o':
        return resl[0] == 'S' and test2(resl)
      else:
        return resl[0] == 'W' and test2(resl)


def printer(resl):
  print("".join(resl))

def check(resl):
  for i in range(1, N-1):
    calc(i, resl)
  return test(resl)

resl = [""]*N
(resl[0], resl[1]) = ('W', 'W')
if check(resl):
  printer(resl)
else:
  resl = [""]*N
  (resl[0], resl[1]) = ('W', 'S')
  if check(resl):
    printer(resl)
  else:
    resl = [""]*N
    (resl[0], resl[1]) = ('S', 'W')
    if check(resl):
      printer(resl)
    else:
      resl = [""]*N
      (resl[0], resl[1]) = ('S', 'S')
      if check(resl):
        printer(resl)
      else:
        print(-1)
