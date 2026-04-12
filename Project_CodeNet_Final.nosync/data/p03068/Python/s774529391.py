N = input()
S = input()
K = input()

targetalpha = S[int(K)-1]
S_list = list(S)

for i in range(0,int(N)):
  if(S_list[i] != targetalpha):
    S_list[i] = "*"
  
S = "".join(S_list)
print(S)
