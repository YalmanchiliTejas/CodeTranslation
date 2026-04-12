N, K = map(int, input().split())

L = [2**(i+2) - 3 for i in range(51)] + [0]
P = [2**(i+1) - 1 for i in range(51)] + [0]

answer = 0
for i in range(N, -1, -1):
  if K == (L[i] + 1) // 2:
    answer += P[i-1] + 1
    break
  elif K > (L[i] + 1) // 2:
    answer += P[i-1] + 1
    K -= (L[i] + 1) // 2
  else:
    K -= 1
  if K == 0:
    break
print(answer)