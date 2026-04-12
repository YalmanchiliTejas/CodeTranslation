N = int(input())
S = input()
K = int(input())
S1 = list(S)
for i in range(N):
    if S[i]!=S[K-1]:
        S1[i]="*"
print("".join(S1))