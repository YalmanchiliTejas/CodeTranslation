N = int(input())
S = input()
K = int(input())

target_string = S[K-1]

ans = S[:]
for i in S:
  if i != target_string:
    ans = ans.replace(i,"*")

print("{}".format(ans))