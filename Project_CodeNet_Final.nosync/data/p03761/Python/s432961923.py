n = int(input())
S = input()
S = sorted([S[i] for i in range(len(S))])
for i in range(1, n):
    S_input = input()
    S_input = sorted([S_input[i] for i in range(len(S_input))])
    result = []
    j_start = 0
    for i in range(len(S)):
        for j in range(j_start, len(S_input)):
            if S[i] == S_input[j]:
                result.append(S[i])
                j_start = j + 1
                break
    S = result

print("".join(S))
