N = int(input())
S = input()
K = int(input())

S_list = list(S)
tmp_letter = S_list[K-1]
for i in range(N):
    if S_list[i] != tmp_letter:
        S_list[i] = '*'

S_changed = "".join(S_list)
print(S_changed)
