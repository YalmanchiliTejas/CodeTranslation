N = input()
S = input()
K = int(input())

replace = S[K - 1]
list_str = list(S)

for i, data in enumerate(S):
    if data != replace:
        list_str[i] = '*'

S = "".join(list_str)

print(S)
