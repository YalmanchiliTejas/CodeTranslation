N = int(input())
S = input()
K = int(input())
c = S[K-1]

answer = ['*'] * N
for i in range(N):
  if S[i] == c:
    answer[i] = c

print(''.join(answer))