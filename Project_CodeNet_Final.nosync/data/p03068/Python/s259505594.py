N = int(input())
S = list(str(input()))
K = int(input())

kome = S[K - 1]

for i in range(N):
    if S[i] != kome:
        S[i] = "*"

s = ""
for i in range(N):
    s += str(S[i])
    
print(s)