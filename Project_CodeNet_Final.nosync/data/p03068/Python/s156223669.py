n = int(input())
S = input()
K = int(input())
temp = S[K-1]
for i in range(n):
    if S[i] != temp:
            S = S[:i]+"*"+S[min(i+1,n):]
print(S)