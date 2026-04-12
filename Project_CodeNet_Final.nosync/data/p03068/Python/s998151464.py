N = int(input())
S = input()
K = int(input())
e = S[K-1]
ans = []
for i in range(N):
  if S[i] != e:
    ans.append("*")
  else:
    ans.append(S[i])
print(''.join(ans))
