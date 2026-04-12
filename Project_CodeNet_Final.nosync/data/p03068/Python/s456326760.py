N = int(input())
S = input()
K = int(input())

string = S[K - 1]

new_string = ""
for i, v in enumerate(S):
    if S[i] != string:
        new_string += "*"
    else:
        new_string += S[i]

print(new_string)
