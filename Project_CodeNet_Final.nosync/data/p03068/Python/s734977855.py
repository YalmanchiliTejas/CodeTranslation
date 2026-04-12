import sys

N = int(sys.stdin.readline())
S = input()
K = int(sys.stdin.readline())

#print(N,K)
#print(type(S))

sk = S[K-1]
out = ""
for s in S:
    if sk==s:
        out += s
#        print("onaji",s)
    else:
        out += "*"
#        print("tigau",s)
print(out)
        