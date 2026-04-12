A,B,C,X,Y=map(int,input().split())

ans1 = int(A*X + B*Y)
if X<=Y:
  ans2 = int(C*2*X + (Y-X)*B)
  ans3 = 10**10
  ans4 = int(2*Y*C)
else:
  ans2 = 10**10
  ans3 = int(C*2*Y + (X-Y)*A)
  ans4 = int(2*X*C)
  
  
print(min(ans1,ans2,ans3,ans4))
