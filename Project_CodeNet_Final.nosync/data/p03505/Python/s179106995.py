K,A,B=map(int,input().split())
if A>=K: print(1)
elif A-B<=0: print(-1)
else: 
  n = (K-A-1) // (A-B) + 1
  print(2*n +1)