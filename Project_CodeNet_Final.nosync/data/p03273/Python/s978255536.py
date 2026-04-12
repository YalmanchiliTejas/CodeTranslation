H,W = map(int,input().split())
A = []
count = 0

#行削除
for i in range(H):
  a0 = input()
  a1 = set(a0)
  a1 = list(a1)
  if(len(a1) != 1):
   a = list(a0)
   A.append(a) 
   count += 1
  else:
    if(a1[0] != '.'):
     a = list(a0)
     A.append(a) 
     count += 1 
    
#列削除   
j_pop = []
for j in range(W):
 B = [] #Aを縦にカットしたもの
 for i in range(count):  
  B.append(A[i][j])
 B = set(B)
 B = list(B)  
 #カットすべき列
 if(len(B) == 1):
  if(B[0] == '.'):
    j_pop.append(j)  


for i in range(count): 
 ans ='' 
 for j in range(W):
  if(j in j_pop):
    continue
  else:
    ans += A[i][j]
 print(ans)