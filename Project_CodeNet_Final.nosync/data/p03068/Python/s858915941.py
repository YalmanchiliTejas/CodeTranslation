N = int(input ())
S = input()
K = int(input ())

i = K -1
char = S[i]
line = ""

for ii in range(len(S)):
    if char != S[ii]:
        line = line + "*"
    else:
        line = line + S[ii]


print(line)

