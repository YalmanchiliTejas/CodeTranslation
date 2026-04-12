n = int(input())
A = [100]*26
for _ in range(n):
  B = [0]*26
  for c in input():
	  B[ord(c)-ord('a')] += 1
  A = [min(a,b) for a, b in zip(A,B)]

ans = ''
for i, a in enumerate(A):
  ans += chr(i+ord('a')) *a
print(ans)