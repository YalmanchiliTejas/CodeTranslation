import bisect

n = int(input())

a = [int(input()) for i in range(n)]

ary = []
ary.append(a[0])

for x in a[1:]:
  i = bisect.bisect_left(ary, x)
  if i == 0:
    ary[0:0] = [x]
  else:
    ary[i-1:i] = [x]
       
print(len(ary))