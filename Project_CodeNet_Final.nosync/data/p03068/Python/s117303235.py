N = input()
S = input()
K = input()

char = S[int(K)-1]

#print(char)

ans = []

for j in range(len(S)):
  #print(S[j])
  if char != S[j]:
    ans.append("*")
    #print("!=")   
  else:
    ans.append(char)
    continue

print("".join(ans))
