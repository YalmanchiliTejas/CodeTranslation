N = int(input())
A = list(map(int, input().split()))
N = len(A) // 3
A = A[:3*N]
#print(N, A)
A.append(0)
A.append(0)

ans = 0
def ind(a, b):
  t = sorted((a, b))
  return t[0] * (N+1) + t[1]
def inv(i):
  b = i % (N+1)
  a = i // (N + 1)
  return a, b

dp = [-1] * (N+1)**2
dp[ind(A[0],A[1])] = 0
current_max = 0
dp1 = [-1] * (N+1)
dp1[A[0]] = 0
dp1[A[1]] = 0

ans = 0
for i in range(0, N):
  a = A[2+3*i] 
  b = A[2+3*i+1]
  c = A[2+3*i+2]
  #print(a,b,c)
  if a == b == c:
    ans+=1
    continue
  dp_new = {}
  for x, y, z in [(a, b, c), (b, c, a), (c, a, b)]:
    # choose 1 (x), leave y, z
    i = ind(y, z)
    if i not in dp_new:
      dp_new[i] = 0
    dp_new[i] = max(dp_new[i], current_max)
    if dp[ind(x, x)] >= 0:
      dp_new[i] = max(dp_new[i], dp[ind(x, x)] + 1)
    
    # choose 2 (x, y), leave t, z
    for t in range(1, N+1):
      i = ind(t,z)
      # Not making three
      if dp1[t] >= 0:
        if i not in dp_new:
          dp_new[i]=0
        dp_new[i] = max(dp_new[i], dp1[t])
      # Making three (x==y)
      if x == y and dp[ind(t, x)] >= 0:
        if i not in dp_new:
          dp_new[i] = 0
        dp_new[i] = max(dp_new[i], dp[ind(t, x)] + 1)
        
  #print(a,b,c)
  #print({inv(i):v for i, v in dp_new.items() })
  for i, s in dp_new.items():
    dp[i] = max(dp[i], s)
    ta, tb = inv(i)
    dp1[ta] = max(dp1[ta], s)
    dp1[tb] = max(dp1[tb], s)
    current_max = max(current_max, s)

#print(doubles)
print(ans + max(dp1))
    
    
        