N=input()
S=input()
K=int(input())
target=S[K-1]
o=""
for s in S:
    if s==target:
        o+=s
    else:
        o+="*"
print(o)
