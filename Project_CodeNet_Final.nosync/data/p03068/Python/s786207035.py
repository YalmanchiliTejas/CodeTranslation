N = int(input())
S = input()
K = int(input())
S_list = list(S)
for i in range(len(S_list)):
    if S_list[i] != S_list[K - 1]:
        S_list[i] = "*"

print("".join(S_list))