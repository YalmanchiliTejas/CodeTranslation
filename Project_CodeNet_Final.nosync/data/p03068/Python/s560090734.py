N = int(input())
S = input()
K = int(input())
change_word = S[K-1]
S_list = list(S)
for i, word in enumerate(S_list):
    if word != change_word:
        S_list[i] = '*'
print(''.join(S_list))