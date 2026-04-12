N = input()
S = list(input())
K = int(input())
s = ""

s_i = S[K-1]
for i in range(len(S)):
    if(S[i]==s_i):
        s += s_i
    else:
        s += "*"
        
print(s)