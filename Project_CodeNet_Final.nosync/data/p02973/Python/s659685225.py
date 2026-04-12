def bisect_left_reverse(a, x):
    if a[0] <= x:
        return 0
    if x < a[-1]:
        return len(a)
    ok = len(a) - 1
    ng = 0
    while (abs(ok - ng) > 1):
        mid = (ok + ng) // 2
        if a[mid] <= x:
            ok = mid
        else:
            ng = mid
    return ok
def bisect_right_reverse(a, x):
    if a[0] < x:
        return 0
    if x <= a[-1]:
        return len(a)
    ok = len(a) - 1
    ng = 0
    while (abs(ok - ng) > 1):
        mid = (ok + ng) // 2
        if a[mid] < x:
            ok = mid
        else:
            ng = mid
    return ok
  
n = int(input())
data = [int(input())]

for i in range(n-1):
  a = int(input())
  idx = bisect_right_reverse(data, a)
  if idx == len(data):
    data.append(a)
  else:
    data[idx] = a

print(len(data))
    
    