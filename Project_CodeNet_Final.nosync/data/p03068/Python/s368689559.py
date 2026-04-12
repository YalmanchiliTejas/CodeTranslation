N = int(input())
S = input()
K = int(input())

S_list = list(S)

for i in range(N):
    if S_list[i] != S_list[K-1]:
        S_list[i] ="*"
    else:
        continue

S_new = ""
for i in S_list:
    S_new += i

print(S_new)