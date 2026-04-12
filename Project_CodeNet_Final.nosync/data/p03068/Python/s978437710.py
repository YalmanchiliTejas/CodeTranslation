N = int(input())
S = input()
K = int(input())

X = S[K-1]
ret = ""
for i in S:
    if i == X:
        ret += X
    else:
        ret += "*"
        
print(ret)