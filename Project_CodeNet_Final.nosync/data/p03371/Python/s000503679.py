A,B,C,X,Y = map(int,input().split())
ans = float("inf")
MAX = max(X,Y)*2
for i in range(0,MAX+1,2): #ABハーフを何枚買うか？必ず偶数枚
  #print(i,X-i//2,Y-i//2)
  temp = A*max((X-i//2),0)+B*max((Y-i//2),0)+C*i
  ans = min(temp,ans)
print(ans)
  