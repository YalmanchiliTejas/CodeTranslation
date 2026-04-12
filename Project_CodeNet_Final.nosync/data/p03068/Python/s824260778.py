N = int(input())
S = input()
K = int(input())
ret = ""
for si in S:
    if si == S[K-1]:
        ret += si
    else:
        ret += "*"
print(ret)