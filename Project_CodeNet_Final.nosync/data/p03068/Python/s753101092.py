N = int(input())
S = input()
K = int(input()) - 1
output = []
for c in S:
    if c == S[K]:
        output.append(c)
    else:
        output.append('*')
print(''.join(output))