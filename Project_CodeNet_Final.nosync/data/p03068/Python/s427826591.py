N = int(input())
S = input()
K = int(input())

target = S[K-1]

index =[]

for i in range(0,N):
   if S[i] != target:
       index.append(i)

for j in range(0,len(index)):
   S = S[:index[j]] + '*' + S[index[j] + 1:]

print(S)
