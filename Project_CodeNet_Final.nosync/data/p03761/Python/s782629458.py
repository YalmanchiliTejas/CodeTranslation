n = int(input())
abc = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 
       'h', 'i', 'j', 'k', 'l', 'm', 'n', 
       'o', 'p', 'q', 'r', 's', 't', 'u', 
       'v', 'w', 'x', 'y', 'z']
G = [99 for i in range(26)]#こっちが答えのリスト
for i in range(n):
  A = [0 for i in range(26)]
  S = list(input())
  for s in S:
    A[abc.index(s)] += 1
  for j in range(26):
    G[j] = min(G[j], A[j])
L = ""
for i in range(26):
  L += abc[i]*G[i]
print(L)