n = int(input())
alpha = "abcdefghijklmnopqrstuvwxyz"
D = {alpha[i]: 100 for i in range(26)}
for i in range(n):
  S = input()
  D2 = {alpha[i]: 0 for i in range(26)}
  for j in range(len(S)):
    D2[S[j]] += 1
  for k in D:
    D[k] = min(D2[k], D[k])
St = ""
for i in range(26):
  St = St[:] + alpha[i] * D[alpha[i]]
print(St)