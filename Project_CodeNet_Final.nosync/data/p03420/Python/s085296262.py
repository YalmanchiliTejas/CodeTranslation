N,K = map(int,input().split())
ans = 0
if K == 0:
  print(N**2)
  exit()
for b in range(K+1,N+1): #bを一個ずつチェックK+1からNまで
  amari = b-K
  loop = N//b
  nokori = max(N%b+1-K,0)
  temp = loop*amari + nokori
  #print(b,amari,loop,nokori,temp)
  ans += temp
print(ans)