N = int(input())
S = input()
K = int(input())
target = S[K-1]
S_list = [c for c in S]
for i,char in enumerate(S_list):
    if char != target:
        S_list[i] = "*"
print("".join(S_list))