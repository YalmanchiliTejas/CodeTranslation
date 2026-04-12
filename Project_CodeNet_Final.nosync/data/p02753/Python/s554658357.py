S = input()
ans = lambda S:"Yes" if S[0] != S[1] or S[0] != S[2] else "No"
print(ans(S))