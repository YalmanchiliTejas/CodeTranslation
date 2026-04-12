N = int(input())
S = input()
K = int(input())

no_replace_char = S[K-1]

output = ""
for c in S :
    if (c == no_replace_char) :
        output += c
    else :
        output += "*"

print(output)