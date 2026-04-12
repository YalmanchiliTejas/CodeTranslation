N = int(input())
S = str(input())
K = int(input())

target = S[K-1]
S = list(S)

for i in range(N):
   if S[i] == target:
       pass
   else:
       S[i] = "*"
        
S = "".join(S)
print(S)
    