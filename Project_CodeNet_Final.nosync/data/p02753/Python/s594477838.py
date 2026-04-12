S = input()

answer = "No"

if not (S[0] == S[1] and S[1] == S[2] and S[0] == S[2]):
    answer = "Yes"

print(answer)
