h,w = list(map(int,input().split()))
h_ch = [0]*h
w_ch = [0]*w
inp = []
for i in range(h):
  inp.append(input())
  for j in range(w):
    h_ch[i] += 1 if inp[-1][j]=="#" else 0
    w_ch[j] += 1 if inp[-1][j]=="#" else 0
    
for i in range(h):
  if h_ch[i] > 0:
    out = ""
    for j in range(w):
      if w_ch[j] > 0:
        out += inp[i][j]
    print(out)