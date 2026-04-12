import numpy as np

n = int(input())
S = [list(input()) for i in range(n)]

alpha = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
aa = [[0]*len(alpha) for i in range(n)]

for i in range(n):
    for j in S[i]:
        a = alpha.index(j)
        aa[i][a] += 1

ans = []

aa = np.array(aa)

for i in range(len(alpha)):
    x = min(aa[:,i])
    ans.append(x)

ans2 =[]
for i in range(len(alpha)):
    ans2.append(alpha[i]*ans[i])

print("".join(ans2))
