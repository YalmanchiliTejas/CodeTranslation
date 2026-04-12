def solve(a,b,c,x,y):
  l = []
  for i in range(10**6):
    s = a*max(x-i,0)+b*max(y-i,0)+c*i*2
    l.append(s)
  return min(l)

        

A,B,C,X,Y = map(int,input().split())
print(solve(A,B,C,X,Y))
