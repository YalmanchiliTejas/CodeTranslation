A,B,C,X,Y = map(int,input().split())

res = A*X +B*Y

for i in range(0,max(X,Y)+1):
  cand = 2*i*C + max(0,X-i)*A + max(0,Y-i)*B
  res = min(res,cand)
print(res)




