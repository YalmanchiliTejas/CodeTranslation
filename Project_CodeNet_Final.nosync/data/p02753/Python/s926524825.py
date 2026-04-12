S = input()
unique_n = len(set([S[0], S[1], S[2]]))

if unique_n == 1:
    ans="No"
else :
    ans = "Yes"
print(ans)