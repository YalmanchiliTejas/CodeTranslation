N = int(input())
S = input()
K = int(input())
s = S[K-1]
for i in range(N):
  if S[i] == s:
    print(s, end="")
  else:
    print("*", end="")
print("")