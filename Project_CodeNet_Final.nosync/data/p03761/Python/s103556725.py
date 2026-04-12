import collections

n = int(input())

alp = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
alpcnt = [50]*26

for i in range(n):
  S = list(input())
  C = collections.Counter(S)
  for j in range(26):
    alpcnt[j] = min(alpcnt[j],C[alp[j]])

for i in range(26):
  print(alp[i]*alpcnt[i], end = "")
  