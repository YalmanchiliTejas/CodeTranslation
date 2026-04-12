A = int(input())
B = input()
C = int(input())
mark = B[C-1]
for i in range(A):
  if B[i] != mark:
    B = B.replace(B[i], '*', 1)
    
 
print(B)