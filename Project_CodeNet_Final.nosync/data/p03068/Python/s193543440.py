N = int(input())
S = (input())
K = int(input())
s=[]
s1=""
for i in range(N):
    if S[i]==S[K-1]:
        s.append(S[i])
    else:
        s.append("*")
for i in range(N):
    s1 += s[i]
print(s1)