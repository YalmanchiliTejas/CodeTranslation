n=int(input())
a = input().split(" ")
lista = [int(n) for n in a]
s=sum(lista)
kotae=0
for i in range(n):
  s-=lista[i]
  kotae+=lista[i]*(s)
print(kotae%(10**9+7))