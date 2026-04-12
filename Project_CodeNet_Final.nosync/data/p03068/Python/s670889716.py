N = int(input())
S = input()
K = int(input())

_ = ""
for s in S:
  if s is not S[K-1]:
    _ = _ + "*"
  else:
    _ = _ + s
print("".join(_))