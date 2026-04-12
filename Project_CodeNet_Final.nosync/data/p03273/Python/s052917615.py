H,W = map(int,input().split())
s=[list(input()) for i in range(H)]
def ts(s):
  ss=[]
  for i in range(len(s)):
    if s[i] != ["."]*len(s[i]):
      ss.append(s[i])
  return ss
sH = ts(s)
sH = list(map(list,zip(*sH)))
sW = ts(sH)
sW = list(map(list,zip(*sW)))
for i in range(len(sW)):
  print("".join(sW[i]))