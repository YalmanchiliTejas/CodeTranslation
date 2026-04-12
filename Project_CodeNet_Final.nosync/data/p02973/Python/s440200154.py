from bisect import bisect_right
n = int(input())
A = [-int(input()) for _ in range(n)]

B = []
v = 0
for a in A:
  b = bisect_right(B,a)  
  if v == b:    
    B.append(a)
    v+=1    
  else:
    B[b] = a    
    
print(len(B))    