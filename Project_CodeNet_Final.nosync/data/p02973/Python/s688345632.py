from bisect import bisect_right
n = int(input())
A = [-int(input()) for _ in range(n)]

B = []
for a in A:
  b = bisect_right(B,a)  
  if len(B) == b:    
    B.append(a)    
  else:
    B[b] = a    
    
print(len(B))    