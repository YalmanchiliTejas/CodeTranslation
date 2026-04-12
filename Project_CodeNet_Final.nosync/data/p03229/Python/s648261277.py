N=int(input())
a = [int(input()) for _ in range(N)]
b = [0]*N

if N%2==1:
  #最大値を中央に置くケース
  a.sort()
  m = N//2
  L,R = m,m
  b[m]=a[-1]
  for i in range(m):
    L -= 1
    R += 1
    if i%2==0:
      b[L]=a[i]
      b[R]=a[i+1]
    else:
      b[L]=a[-2-(i-1)]
      b[R]=a[-3-(i-1)]
  ans1=0
  for i in range(1,N):
    ans1 += abs(b[i]-b[i-1])
  #print(b)
  
  #最小値を中央に置くケース
  a.sort()
  m = N//2
  L,R = m,m
  b[m]=a[0]
  for i in range(m):
    L -= 1
    R += 1
    if i%2==0:
      b[L]=a[-1-i]
      b[R]=a[-2-i]
    else:
      b[L]=a[(i-1)+1]
      b[R]=a[(i-1)+2]
  ans2=0
  for i in range(1,N):
    ans2 += abs(b[i]-b[i-1])
  ans=max(ans1,ans2)
  #print(b)
  print(ans)

else:
  a.sort()
  m = N//2
  L,R = m-1,m
  b[L]=a[0]
  b[R]=a[-1]
  
  for i in range(m-1):
    L -= 1
    R += 1
    if i%2==0:
      b[L]=a[-2-i]
      b[R]=a[i+1]
    else:
      b[L]=a[i+1]
      b[R]=a[-2-i]
  ans=0
  for i in range(1,N):
    ans += abs(b[i]-b[i-1])
  #print(b)
  print(ans)  
  