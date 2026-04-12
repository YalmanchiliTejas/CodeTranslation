N = int(input())
S = input()
K = int(input())

a = S[K-1]

answer = ''
for i,j in enumerate(S):
  if j == a:
    answer += j
  else:
    answer += '*'

print(answer)