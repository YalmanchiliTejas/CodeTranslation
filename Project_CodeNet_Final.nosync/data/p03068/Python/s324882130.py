N = int(input())
S = input()
K = int(input())

str_list = list(S)

for i in range(N):
    if str_list[K - 1] != str_list[i]:
        str_list[i] = '*'

S = "".join(str_list)
print(S)
