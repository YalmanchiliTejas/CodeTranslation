N = int(input())
S = input()
K = int(input())
temp = S[K - 1]
c_list = list(S)
for i in range(N):
    if temp != c_list[i]:
        c_list[i] = "*"
print("".join(c_list))