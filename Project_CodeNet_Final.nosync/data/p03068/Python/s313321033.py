#A, B, C = map(int,input().split())


N = int(input())
S = input()
K = int(input())



tmp = S[K-1]

ans = []
for i in S:
    if (i == tmp) :
        ans.append(tmp)
    else:
        ans.append("*")

print("".join(ans))