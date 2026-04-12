N = int(input())
S = input()
K = int(input())

r_list = []
k = S[K-1]
for s in S:
  if s == k:
    r_list.append(s)
  else:
    r_list.append("*")
r_seq = "".join(r_list)
print(r_seq)