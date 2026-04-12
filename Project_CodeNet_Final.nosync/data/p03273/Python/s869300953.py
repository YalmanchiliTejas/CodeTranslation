h,w = map(int, input().split())
aij = [list(input()) for i in range(h)]
aij1 = []
for r in aij:
    if r.count(".")==w:
        continue
    aij1.append(r)

h_r = len(aij1)
aij1_t = [[""]*h_r for i in range(w)]
for i in range(h_r):
    for j in range(w):
          aij1_t[j][i] = aij1[i][j]
          
ans_t = []
for c in aij1_t:
    if c.count(".") == h_r:
        continue
    ans_t.append(c)
    
w_r = len(ans_t)
ans = [[""]*w_r for i in range(h_r)]
for i in range(h_r):
    for j in range(w_r):
        ans[i][j] = ans_t[j][i]

for r in ans:
    print("".join(r))