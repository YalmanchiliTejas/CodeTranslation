N = int(input())
S = input()
K = int(input())
a = ""
b = S[K - 1]
for i in range(N):
  a = S[i]
  if (a == b):
    print(a,end = "")
  else:
    print("*",end = "")