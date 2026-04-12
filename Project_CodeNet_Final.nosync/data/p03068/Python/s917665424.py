N = int(input())
S = input()
K = int(input())
 
cha = S[K-1]
list_ = [s for s in S]
for i in range(N):
  if cha != S[i]:
    list_[i] = "*"
print("".join(list_))
