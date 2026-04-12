import bisect
N = int(input())
A = [int(input()) for _ in range(N)]
b = []
for a in A[::-1]:
  idx = bisect.bisect_right(b, a)
  if len(b) <= idx:
    b.append(a)
  else:
    b[idx] = a

print(len(b))
