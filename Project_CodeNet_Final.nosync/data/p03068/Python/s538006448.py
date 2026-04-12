N = int(input())
S = input()
K = int(input())
k = S[K-1]
print("".join([k if i==" " else "*" for i in S.replace(k," ")]))