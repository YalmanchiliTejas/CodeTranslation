N = int(input())
S = input()
K = int(input())

Slist = list(S) 
e = Slist[K-1]
for i in range(N):
  if Slist[i] != e:
    Slist[i] = '*'
print("".join(Slist))