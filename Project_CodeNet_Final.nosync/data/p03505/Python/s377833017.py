K, A, B = map(int, input().split())
if A >= K:
  r = 1
elif B >= A:
  r = -1
else:
  r = (K-A +A-B-1)//(A-B)*2+1
print(r)
