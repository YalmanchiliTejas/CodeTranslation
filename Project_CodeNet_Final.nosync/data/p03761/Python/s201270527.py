n = int(input())
S = [input() for i in range(n)] 
alphabet = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
num = [[0 for _ in range(n)] for _ in range(26)]
ans = []
for fig in alphabet:
  for i in range(n):
    num[alphabet.index(fig)][i] = S[i].count(fig)
  for j in range(min(num[alphabet.index(fig)])):
    ans.append(fig)
print(("").join(ans))