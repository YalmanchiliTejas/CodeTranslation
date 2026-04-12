N = int(input())
S = input()
K = int(input())
lst = list(S)
for i in range(N):
  if lst[i] == lst[K-1]:
    pass
  else:
    lst[i] = "*"
print("".join(lst))