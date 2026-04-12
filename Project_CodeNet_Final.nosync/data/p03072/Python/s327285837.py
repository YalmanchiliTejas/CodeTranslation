N = int(input())
H = list(map(int,input().split()))
A = H[0]
result = 0
for i in range(len(H)):
  if A <= H[i]:
    result += 1
    A = H[i]
  else:
    None
print(result)
