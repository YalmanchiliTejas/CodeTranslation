N=int(input())
L=input()
L=L.replace('o','1')
L=L.replace('x','0')
L=list(map(int,list(L)))
init = [[1, 1], [1, 0], [0, 1], [0, 0]]
ans = -1
for ii in init:
  ret = [None]*(N)
  ret[0] = ii[1] 
  pR = ii[0]
  for i in range(1, N):
    ret[i]= ~ ((~ (ret[i-1] ^ L[i-1])) ^ pR)
    pR = ret[i-1]
  if ii[0]==ret[-1] and ret[0]==~ ((~ (ret[-1] ^ L[-1])) ^ pR):
    ans = ret
    break

if ans == -1:
  print(ans)
else:
  ans=list(map(str,ans))
  ans=''.join(ans)
  ans=ans.replace('1','S')
  ans=ans.replace('0','W')
  print(ans)