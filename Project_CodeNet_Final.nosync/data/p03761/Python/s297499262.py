N = int(input())
ans = ""
alpha = [50] * 26
alpha2num = lambda c: ord(c) - ord('a') #alphaを数字に 0-25
num2alpha = lambda c: chr(c + 96)#数字をalphaに数字は1-26

for i in range(N):
  S = str(input())
  y = [0] * 26
  for j in range(len(S)):#max 50
    x = alpha2num(S[j])
    #print(x, S[j])
    y[x] += 1
  for j in range(26):
    alpha[j] = min(alpha[j], y[j])
  
for i in range(26):
  numx = alpha[i]
  A = num2alpha(i + 1)
  for j in range(numx):
    print(A, end = "")