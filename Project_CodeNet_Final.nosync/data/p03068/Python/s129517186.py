N = int(input())
S = input().strip()
K = int(input())
x = S[K-1]
z = ""
for i in range(N):
    if S[i]==x:
        z += x
    else:
        z += "*"
print(z)