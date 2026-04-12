N = int(input())
S = input()
K = int(input())

s = S[K-1]
newS =''
for i in range(N):
    if S[i] != s:
        newS = newS + '*'
    else:
        newS = newS + s
        
print(newS)