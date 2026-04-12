H,W=list(map(int, input().split()))
A=[list(input()) for _ in range(H)]
S={i for i in range(H)}
T={j for j in range(W)}
for i in range(H):
  if set(A[i])=={'.'}:
    S-={i}
for j in range(W):
  for i in range(H):
    if A[i][j]=='#':
      break
  else:
    T-={j}
S=sorted(list(S))
T=sorted(list(T))
for i in S:
  ans=[]
  for j in T:
    ans.append(A[i][j])
  print(''.join(ans))