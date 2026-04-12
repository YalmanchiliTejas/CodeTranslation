N=int(input())
S=input()
K=int(input())
s=S[K-1]

X=[]*N

for i in S:

    if i==s:
        X.append(i)
    else:
        X.append("*")

Y="".join(X)
print(Y)
