N = int(input())
S=input()
K=int(input())
r = S[K-1]
Ans = []
for i in S:
    if i != r:
        Ans.append("*")
    else:
        Ans.append(i)
print(''.join(Ans))