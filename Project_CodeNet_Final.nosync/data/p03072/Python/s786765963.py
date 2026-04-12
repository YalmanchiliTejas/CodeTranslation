N=int(input())
H=[int(x) for x in input().split()]
can_watch = 0
for i in range(N):
  if i > 0:
    if H[i] >= max(H[:i]):
      can_watch = can_watch + 1
    else:
      pass
  else:
    can_watch = can_watch + 1
print(can_watch)