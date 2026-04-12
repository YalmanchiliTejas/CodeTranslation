N,X=map(int,input().split())

lv_len=[1]
lv_pad=[1]

for i in range(N):
  lv_len.append(lv_len[i]*2+3)
  lv_pad.append(lv_pad[i]*2+1)

def solve(n,x):
  if n==0:
    return 1
  elif x==1:
    return 0
  else:
    if x <= lv_len[n]//2:
      return solve(n-1,x-1)
    elif x == lv_len[n]//2 +1:
      return 1 + solve(n-1,x-2)
    else:
      return lv_pad[n-1] + 1 + solve(n-1,x-(lv_len[n-1]+2))
    
print(solve(N,X))