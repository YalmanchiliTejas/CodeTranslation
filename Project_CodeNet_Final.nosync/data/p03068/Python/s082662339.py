N = int(input())
S = input()
K = int(input())

k_char = S[K-1]
S_aranged = ""

for i in S:
    if i != k_char:
        S_aranged += "*"
    else:
        S_aranged += k_char

print(S_aranged)