H,W = map(int,input().split())
A = [input() for i in range(H)]
B = []
for row in A:
    if all(c=='.' for c in row): continue
    B.append(row)

ans = ['' for _ in range(len(B))]
for col in zip(*B):
    if all(c=='.' for c in col): continue
    for i,c in enumerate(col):
        ans[i] += c

for row in ans:
    print(row)