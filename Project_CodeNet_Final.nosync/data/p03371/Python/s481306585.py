A,B,C,X,Y = input().split(' ')

#print(A,B,C,X,Y)

ans = 10 ** 12
for i in range(0,100001):
  tmp = int(C) * 2 * i + int(A) * max(int(X)-i,0) + int(B) * max(int(Y)-i,0)
  ans = min(ans,tmp)

print(ans)