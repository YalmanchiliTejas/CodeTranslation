"""
map(int,input().split())

X = input().split()
x = []
for i in range(0,len(X)):
    x.append(X[i])

"""

N = int(input())
S = input()
K = int(input())-1

sls = []

for w in S:
    sls.append(w)

getW = S[K]
out = ""

for i in range(0,N):
    if sls[i] != getW:
        sls[i] = "*"
    out += sls[i]


print(out)