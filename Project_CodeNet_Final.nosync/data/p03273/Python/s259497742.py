def t(l_2d):
  return [list(i) for i in zip(*l_2d)]

def clean(a):
  a_white = ["."]*len(a[0])
  #print(a_white)
  a_ret=[]
  for ai in a:
    if ai!=a_white:
      a_ret.append(ai)
  return a_ret


h,w = map(int, input().split())
a = [list(input()) for i in range(h)]

a = clean(a)
#print(t(a))
a = t(clean(t(a)))

for ai in a:
  for aii in ai:
    print(aii, end="")
  print("")