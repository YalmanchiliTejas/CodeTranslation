S = input()

n =0
for i in range(2):
    if S[i] !=S[i+1]:
        n += 1
  
    
if S[0] != S[2]:
    n += 1
        
if n > 0:
    print('Yes')
else:
    print('No')